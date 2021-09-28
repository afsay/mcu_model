#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <string.h>
#include "MKL46Z4_bsp.h"
#include "pins.h"

namespace uart0_namespace {
	 typedef struct __attribute__((packed)){
	 	 uint8_t SBR:5;
	 	 uint8_t SBNS:1;
	 	 uint8_t RXEDGIE:1;
	 	 uint8_t LBKDIE:1;
	 } BDH_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t SBR:8;
	 } BDL_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t PT:1;
	 	 uint8_t PE:1;
	 	 uint8_t ILT:1;
	 	 uint8_t WAKE:1;
	 	 uint8_t M:1;
	 	 uint8_t RSRC:1;
	 	 uint8_t DOZEEN:1;
	 	 uint8_t LOOPS:1;
	 } C1_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t SBK:1;
	 	 uint8_t RWU:1;
	 	 uint8_t RE:1;
	 	 uint8_t TE:1;
	 	 uint8_t ILIE:1;
	 	 uint8_t RIE:1;
	 	 uint8_t TCIE:1;
	 	 uint8_t TIE:1;
	 } C2_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t PF:1;
	 	 uint8_t FE:1;
	 	 uint8_t NF:1;
	 	 uint8_t OR:1;
	 	 uint8_t IDLE:1;
	 	 uint8_t RDRF:1;
	 	 uint8_t TC:1;
	 	 uint8_t TDRE:1;
	 } S1_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t RAF:1;
	 	 uint8_t LBKDE:1;
	 	 uint8_t BRK13:1;
	 	 uint8_t RWUID:1;
	 	 uint8_t RXINV:1;
	 	 uint8_t MSBF:1;
	 	 uint8_t RXEDGIF:1;
	 	 uint8_t LBKDIF:1;
	 } S2_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t PEIE:1;
	 	 uint8_t FEIE:1;
	 	 uint8_t NEIE:1;
	 	 uint8_t ORIE:1;
	 	 uint8_t TXINV:1;
	 	 uint8_t TXDIR:1;
	 	 uint8_t R9T8:1;
	 	 uint8_t R8T9:1;
	 } C3_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t RT:8;
	 } D_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t MA:8;
	 } MA1_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t MA:8;
	 } MA2_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t OSR:5;
	 	 uint8_t M10:1;
	 	 uint8_t MAEN2:1;
	 	 uint8_t MAEN1:1;
	 } C4_Type;

	 typedef struct {
	 	 uint8_t RESYNCDIS:1;
	 	 uint8_t BOTHEDGE:1;
	 	 uint8_t Reserved0:3;
	 	 uint8_t RDMAE:1;
	 	 uint8_t Reserved1:1;
	 	 uint8_t TDMAE:1;
	 } __attribute__((packed)) C5_Type;

	 typedef struct {
	 	__IO BDH_Type BDH;
	 	__IO BDL_Type BDL;
	 	__IO C1_Type C1;
	 	__IO C2_Type C2;
	 	__IO S1_Type S1;
	 	__IO S2_Type S2;
	 	__IO C3_Type C3;
	 	__IO D_Type D;
	 	__IO MA1_Type MA1;
	 	__IO MA2_Type MA2;
	 	__IO C4_Type C4;
	 	__IO C5_Type C5;
	 } __attribute__((packed)) UART0_Type;

}

using namespace uart0_namespace;

class UART0{
	UART0_Type *uart0;
public:
	UART0(unsigned int MODULE_BASE){
		uart0 = (UART0_Type *)MODULE_BASE;
	}
	void enable_tx(bool value){
		uart0->C2.TE = value;
	}
	void enable_rx(bool value){
		uart0->C2.RE = value;
	}
	void enable_rx_int(bool value){
		uart0->C2.RIE = value;
	}
	void set_baud_rate(uint16_t osr, uint8_t sbr){
		uart0->BDH.SBR = (uint8_t)(sbr >> 8);
		uart0->BDL.SBR = (uint8_t)(sbr & 0xFF);
		uart0->C4.OSR = osr;
	}
	void write(const char *str){
		for(int i = 0; i < (int)strlen(str); i++)
		{
			while(uart0->S1.TDRE == 0){;;}
			uart0->D.RT = str[i];
		}
	}

	void uart_putc(uint8_t value){
		while(uart0->S1.TDRE == 0){;;}
		uart0->D.RT = value;
	}
	uint8_t read(){
		return uart0->D.RT;
	}
};

#endif
