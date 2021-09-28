#ifndef SIM_H
#define SIM_H

#include <stdint.h>
#include "MKL46Z4_bsp.h"
#include "pins.h"

typedef struct __attribute__((packed)){
	uint32_t RES1:18;
	uint8_t OSC32KSEL:2;
	uint16_t RES2:9;
	uint8_t USBVSTBY:1;
	uint8_t USBSSTBY:1;
	uint8_t USBREGEN:1;
} SOPT1_Type;

typedef struct __attribute__((packed)){
	uint32_t RES1:24;
	uint8_t URWE:1;
	uint8_t UVSWE:1;
	uint8_t USSWE:1;
	uint8_t RES2:5;
} SOPT1CFG_Type;

typedef struct __attribute__((packed)){
	uint8_t RES1:4;
	uint8_t RTCCLKOUTSEL:1;
	uint8_t CLKOUTSEL:3;
	uint8_t RES2:8;
	uint8_t PLLFLLSEL:1;
	uint8_t RES3:1;
	uint8_t USBSRC:1;
	uint8_t RES4:5;
	uint8_t TPMSRC:2;
	uint8_t UART0SRC:2;
	uint8_t RES5:4;
} SOPT2_Type;

typedef struct __attribute__((packed)){
	uint32_t RES1:18;
	uint8_t TPM1CH0SRC:2;
	uint8_t TPM2CH0SRC:1;
	uint8_t RES2:3;
	uint8_t TPM0CLKSEL:1;
	uint8_t TPM1CLKSEL:1;
	uint8_t TPM2CLKSEL:1;
	uint8_t RES3:5;
} SOPT4_Type;

typedef struct __attribute__((packed)){
	uint8_t UART0TXSRC:2;
	uint8_t UART0RXSRC:1;
	uint8_t RES1:1;
	uint8_t UART1TXSRC:2;
	uint8_t UART1RXSRC:1;
	uint16_t RES2:9;
	uint8_t UART0ODE:1;
	uint8_t UART1ODE:1;
	uint8_t UART2ODE:1;
	uint16_t RES3:13;
} SOPT5_Type;

typedef struct __attribute__((packed)){
	uint8_t ADC0TRGSEL:4;
	uint8_t ADC0PRETRGSEL:1;
	uint8_t RES1:2;
	uint8_t ADC0ALTTRGEN:1;
	uint32_t RES2:24;
} SOPT7_Type;

typedef struct {
	uint16_t PINID:4;
	uint16_t RES1:3;
	uint16_t DIEID:5;
	uint16_t REVID:4;
	uint16_t SRAMSIZE:4;
	uint16_t SERIESID:4;
	uint16_t SUBFAMID:4;
	uint16_t FAMID:4;
} __attribute__((packed)) SDID_Type;

typedef struct {
	const uint16_t RES1:4;	//This read-only field is reserved and always has the value 0.
	const uint16_t RES2:2; //This read-only field is reserved and always has the value 1.
	uint16_t I2C0:1;
	uint16_t I2C1:1;
	uint16_t RES3:2;
	uint16_t UART0:1;
	uint16_t UART1:1;
	uint16_t UART2:1;
	uint16_t RES4:5;
	uint16_t USBOTG:1;
	uint16_t CMP:1;
	uint16_t RES5:1;
	uint16_t SPI0:1;
	uint16_t SPI1:1;
	uint16_t RES6:4;	//This read-only field is reserved and always has the value 0.
	uint16_t RES7:4;	//This read-only field is reserved and always has the value 1.
} __attribute__((packed)) SCGC4_Type;

typedef struct {
	uint16_t LPTMR:1;
	uint16_t RES1:1; //This read-only field is reserved and always has the value 1.
	uint16_t RES2:3; //This read-only field is reserved and always has the value 0.
	uint16_t TSI:1;
	uint16_t RES3:1; //This read-only field is reserved and always has the value 0.
	uint16_t RES4:2; //This read-only field is reserved and always has the value 1.
	uint16_t PORTA:1;
	uint16_t PORTB:1;
	uint16_t PORTC:1;
	uint16_t PORTD:1;
	uint16_t PORTE:1;
	uint16_t RES5:5;
	uint16_t SLCD:1;
	uint16_t RES6:12;
} __attribute__((packed)) SCGC5_Type;

typedef struct __attribute__((packed)){
	uint8_t FTF:1;	/*reset value is 1*/
	uint8_t DMAMUX:1;
	uint16_t RES1:13;
	uint8_t I2S:1;
	uint8_t RES2:7;
	uint8_t PIT:1;
	uint8_t TPM0:1;
	uint8_t TPM1:1;
	uint8_t TPM2:1;
	uint8_t ADC0:1;
	uint8_t RES3:1;
	uint8_t RTC:1;
	uint8_t RES4:1;
	uint8_t DAC0:1;
} SCGC6_Type;

typedef struct __attribute__((packed)){
	uint8_t RES1:8;
	uint8_t DMA:1;	/*reset value is 1*/
	uint32_t RES2:23;
} SCGC7_Type;

typedef struct __attribute__((packed)){
	uint16_t RES1:16;
	uint8_t OUTDIV4:3;	/*reset value is 1*/
	uint16_t RES2:9;
	uint8_t OUTDIV1:4; 	/*reset value is dependent to FTFA_FOPT[LPBOOT]*/
} CLKDIV1_Type;

typedef struct __attribute__((packed)){
	uint8_t FLASHDIS:1;
	uint8_t FLASHDOZE:1;
	uint32_t RES1:22;
	uint8_t PFSIZE:4;
	uint8_t RES2:4;
} FCFG1_Type;

typedef struct __attribute__((packed)){
	uint16_t RES1:16;
	uint8_t MAXADDR1:7;
	uint8_t RES2:1;
	uint8_t MAXADDR0:7;
	uint8_t RES3:1;
} FCFG2_Type;

typedef struct __attribute__((packed)){
	uint16_t UID:16;
	uint16_t RES1:16;
} UIDMH_Type;

typedef struct __attribute__((packed)){
	uint32_t UID:32;
} UIDML_Type;

typedef struct __attribute__((packed)){
	uint32_t UID:32;
} UIDL_Type;

typedef struct __attribute__((packed)){
	uint8_t COPW:1;
	uint8_t COPCLKS:1;
	uint8_t COPT:2;
	uint32_t RES1:28;
} COPC_Type;

typedef struct __attribute__((packed)){
	uint8_t SRVCOP:8;
	uint32_t RES1:24;
} SRVCOP_Type;


typedef struct {
  __IO SOPT1_Type SOPT1;                             /**< System Options Register 1, offset: 0x0 */
  __IO SOPT1CFG_Type SOPT1CFG;                          /**< SOPT1 Configuration Register, offset: 0x4 */
       uint8_t RESERVED_0[4092];
  __IO SOPT2_Type SOPT2;                             /**< System Options Register 2, offset: 0x1004 */
       uint8_t RESERVED_1[4];
  __IO SOPT4_Type SOPT4;                             /**< System Options Register 4, offset: 0x100C */
  __IO SOPT5_Type SOPT5;                             /**< System Options Register 5, offset: 0x1010 */
       uint8_t RESERVED_2[4];
  __IO SOPT7_Type SOPT7;                             /**< System Options Register 7, offset: 0x1018 */
       uint8_t RESERVED_3[8];
  __I  SDID_Type SDID;                              /**< System Device Identification Register, offset: 0x1024 */
       uint8_t RESERVED_4[12];
  __IO SCGC4_Type SCGC4;                             /**< System Clock Gating Control Register 4, offset: 0x1034 */
  __IO SCGC5_Type SCGC5;                             /**< System Clock Gating Control Register 5, offset: 0x1038 */
  __IO SCGC6_Type SCGC6;                             /**< System Clock Gating Control Register 6, offset: 0x103C */
  __IO SCGC7_Type SCGC7;                             /**< System Clock Gating Control Register 7, offset: 0x1040 */
  __IO CLKDIV1_Type CLKDIV1;                           /**< System Clock Divider Register 1, offset: 0x1044 */
       uint8_t RESERVED_5[4];
  __IO FCFG1_Type FCFG1;                             /**< Flash Configuration Register 1, offset: 0x104C */
  __I  FCFG2_Type FCFG2;                             /**< Flash Configuration Register 2, offset: 0x1050 */
       uint8_t RESERVED_6[4];
  __I  UIDMH_Type UIDMH;                             /**< Unique Identification Register Mid-High, offset: 0x1058 */
  __I  UIDML_Type UIDML;                             /**< Unique Identification Register Mid Low, offset: 0x105C */
  __I  UIDL_Type UIDL;                              /**< Unique Identification Register Low, offset: 0x1060 */
       uint8_t RESERVED_7[156];
  __IO COPC_Type COPC;                              /**< COP Control Register, offset: 0x1100 */
  __O  SRVCOP_Type SRVCOP;                            /**< Service COP, offset: 0x1104 */
} SIM_t;

class SIM {
	SIM_t *sim;

public:
	SIM(unsigned int MODULE_BASE){
		sim = ((SIM_t *) MODULE_BASE);
	}
	void enable_porta_clock(){
		sim->SCGC5.PORTA = 1;
	}
	void enable_uart0_clock(){
		sim->SOPT2.PLLFLLSEL = 0b1u;
		sim->SOPT2.UART0SRC = 0b01u; //MCGFLLCLK clock or MCGPLLCLK/2 clock
		sim->SCGC4.UART0 = 1;
	}
	void disable_watchdog(){
		sim->COPC.COPT = 0;
	}
	void set_outdiv1(uint8_t div1){
		sim->CLKDIV1.OUTDIV1 = div1;
	}
	void set_outdiv4(uint8_t div1){
			sim->CLKDIV1.OUTDIV4 = div1;
	}
};

#endif
