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
 * @file    MKL46Z4_OOP_Model.cpp
 * @brief   Application entry point.
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "MKL46Z4_bsp.h"
#include "microcontroller.h"
#include "global_vars.h"
#include "command_parser.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

char cmd_buffer[256];

int buff_index = 0;

void UART0_DriverIRQHandler(void){
	uint8_t read_val = MicroController::Uart0.read();

	if(buff_index==256){
		buff_index=0;
		memset(cmd_buffer, 0, 256);
	}
	if (read_val == 8) {
		if (buff_index == 0) return;
		cmd_buffer[--buff_index]=0;
		putchar(read_val);
		putchar(' ');
		putchar(read_val);
		return;
	}
	if(read_val == '\r' || read_val == '\n'){
		//MicroController::Uart0.write("\r\n");
		//puts("deneme");
		if(strlen(cmd_buffer) > 0) printf("\r\n");

		parse(cmd_buffer);

		printf("%s", prompt);//MicroController::Uart0.write(prompt);

		buff_index=0;
		memset(cmd_buffer, 0, 256);
	}
	else {
		cmd_buffer[buff_index++] = read_val;
		putchar(read_val);
	}
}

void SysTick_HandlerIRQ(void)
{
	one_ms++;
}


int main(void) {

    MicroController::Sim.disable_watchdog();
    /*System is in FEI mode at boot, set to 48Mhz*/
    //MicroController::Mcg.set_drst_drs(1);
    //MicroController::Mcg.set_dmx32(1);
    MicroController::set_external_48mhz_clock();
    MicroController::Sim.enable_porta_clock();
    MicroController::Sim.enable_uart0_clock();

    /*Set PTA1 and PTA2 as UART0_RX, UART0_TX*/
    MicroController::PortA.pin_mux_control(PIN1, ALT2_PIN);
    MicroController::PortA.pin_mux_control(PIN2, ALT2_PIN);

    MicroController::Uart0.set_baud_rate(31u, 13u); //115200
    MicroController::Uart0.enable_rx_int(true); //115200
    MicroController::Uart0.enable_rx(true);
    MicroController::Uart0.enable_tx(true);

    MicroController::PortA.pin_mux_control(PIN16, GPIO_PIN);
    MicroController::PortA.set_pull(PIN16, ENABLE_P);
    MicroController::PortA.set_pull_select(PIN16, DOWN_PS);
    MicroController::PortA.set_drive_strength(PIN16, HIGH_DS);
    MicroController::PortA.set_slew_rate(PIN16, SLOW_SR);
    MicroController::GpioA.set_direction(PIN16_MASK, OUTPUT);

    MicroController::PortA.pin_mux_control(PIN17, GPIO_PIN);
    MicroController::PortA.set_pull(PIN17, ENABLE_P);
    MicroController::PortA.set_pull_select(PIN17, DOWN_PS);
    MicroController::PortA.set_slew_rate(PIN17, SLOW_SR);
    MicroController::GpioA.set_direction(PIN17_MASK, OUTPUT);


    NVIC_EnableIRQ(UART0_IRQn); //enable uart0 in NVIC

    char i;
    for(i='a';i<='z';++i){
          set_reg(i,0.0f);
    }

    strncpy(prompt,"\r\n>",200);
    //setbuf(stdout, NULL);
    printf("%s", prompt);
    while(true){
    	;;
    }

    return 0 ;
}
