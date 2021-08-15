/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    arducam-test.cpp
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC55S69_cm33_core0.h"
#include "fsl_debug_console.h"
#include "ArduCAM/ArduCAM.h"
extern "C" {
#include "lcd/lcd.h"
}

/* TODO: insert other include files here. */
/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

#define OV5642_MAX_FIFO_SIZE		0x7FFFFF
#define BUF_SIZE 4096

uint8_t buf[BUF_SIZE];

void delay(uint32_t ms)
{
	SDK_DelayAtLeastUs(ms*1000, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
}

void arducam_test(void)
{
    /* arducam */
	uint8_t temp = 0;
	uint8_t temp_last = 0;
    uint8_t vid, pid;

    ArduCAM myCAM(OV5642, 100);

    myCAM.write_reg(0x07, 0x80);
    delay(100);
    myCAM.write_reg(0x07, 0x00);
    delay(100);

    myCAM.write_reg(ARDUCHIP_TEST1, 0x55);
    temp = myCAM.read_reg(ARDUCHIP_TEST1);
    if (temp != 0x55)
    {
    	PRINTF("Incorrect ArduCAM SPI test register return value!\r\n");
    	return;
    }

    myCAM.rdSensorReg16_8(OV5642_CHIPID_HIGH, &vid);
    myCAM.rdSensorReg16_8(OV5642_CHIPID_LOW, &pid);
    if((vid != 0x56) || (pid != 0x42))
    {
    	PRINTF("Incorrect OV5642 module VID/PID values!\r\n");
    	return;
    }
    else
    {
    	uint8_t buf[256];
    	uint8_t VL;
    	size_t m = 0;
    	uint8_t resolution = OV5642_320x240;
    	size_t line = 320, column = 240;
    	size_t length;
    	bool is_header = false;

    	PRINTF("Communication with OV542 success!\r\n");

    	myCAM.set_format(JPEG);
    	myCAM.InitCAM();
    	myCAM.write_reg(ARDUCHIP_TIM, VSYNC_LEVEL_MASK);
    	myCAM.clear_fifo_flag();
    	myCAM.write_reg(ARDUCHIP_FRAMES, 0x03);

    	myCAM.flush_fifo();
    	myCAM.clear_fifo_flag();

    	myCAM.OV5642_set_JPEG_size(OV5642_320x240);
    	delay(1000);

    	myCAM.start_capture();
    	PRINTF("Start Capture\r\n");
    	while( !myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK));
    	PRINTF("Capture Done\r\n");

    	length = myCAM.read_fifo_length();
    	PRINTF("Length Capture = %d\r\n", length);

    	if (length >= MAX_FIFO_SIZE) //8M
    	{
    		PRINTF("Over size.");
    		return;
    	}
    	if (length == 0 ) //0 kb
    	{
    		PRINTF("Size is 0.");
    		return;
    	}

    	myCAM.CS_LOW();
    	myCAM.set_fifo_burst();
    	while(length--)
    	{
    		temp_last = temp;
    		temp = myCAM.read_fifo();

    		if ( (temp == 0xD9) && (temp_last == 0xFF) )
    		{
    			buf[m++] = temp;
    			myCAM.CS_HIGH();
    			for(int i = 0; i < m; i++)
    			{
    				PRINTF("%d,", buf[i]);
    			}
    			PRINTF("\r\n");
    			m = 0;
    			is_header = false;
    			myCAM.CS_LOW();
    			myCAM.set_fifo_burst();
    		}

    		if(is_header == true)
    		{
    			if(m < 256)
    			{
    				buf[m++] = temp;
    			}
    			else
    			{
    				myCAM.CS_HIGH();
    				for(int i = 0; i < m; i++)
    				{
    					PRINTF("%d,", buf[i]);
    				}
    				PRINTF("\r\n");
    				m = 0;
    				buf[m++] = temp;
    				myCAM.CS_LOW();
    				myCAM.set_fifo_burst();
    			}
    		}
    		else if ((temp == 0xD8) & (temp_last == 0xFF))
    		{
    			is_header = true;
    			myCAM.CS_HIGH();

    			myCAM.CS_LOW();
    			myCAM.set_fifo_burst();
    			buf[m++] = temp_last;
    			buf[m++] = temp;
    		}
    	}
    	myCAM.CS_HIGH();
    }
}

int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    PRINTF("ARDUCAM_TEST\n");

    arducam_test();

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}
