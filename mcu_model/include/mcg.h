#ifndef MCG_H
#define MCG_H

#include <stdint.h>
#include "sim.h"
#include "MKL46Z4_bsp.h"
#include "pins.h"

namespace mcg_namespace {
	 typedef struct __attribute__((packed)){
	 	 uint8_t IREFSTEN:1;
	 	 uint8_t IRCLKEN:1;
	 	 uint8_t IREFS:1;
	 	 uint8_t FRDIV:3;
	 	 uint8_t CLKS:2;
	 } C1_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t IRCS:1;
	 	 uint8_t LP:1;
	 	 uint8_t EREFS0:1;
	 	 uint8_t HGO0:1;
	 	 uint8_t RANGE0:2;
	 	 uint8_t FCFTRIM:1;
	 	 uint8_t LOCRE0:1;
	 } C2_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t SCTRIM:8;
	 } C3_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t SCFTRIM:1;
	 	 uint8_t FCTRIM:4;
	 	 uint8_t DRST_DRS:2;
	 	 uint8_t DMX32:1;
	 } C4_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t PRDIV0:5;
	 	 uint8_t PLLSTEN0:1;
	 	 uint8_t PLLCLKEN0:1;
	 	 uint8_t Reserved0:1;
	 } C5_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t VDIV0:5;
	 	 uint8_t CME0:1;
	 	 uint8_t PLLS:1;
	 	 uint8_t LOLIE0:1;
	 } C6_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t IRCST:1;
	 	 uint8_t OSCINIT0:1;
	 	 uint8_t CLKST:2;
	 	 uint8_t IREFST:1;
	 	 uint8_t PLLST:1;
	 	 uint8_t LOCK0:1;
	 	 uint8_t LOLS0:1;
	 } S_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t LOCS0:1;
	 	 uint8_t FCRDIV:3;
	 	 uint8_t FLTPRSRV:1;
	 	 uint8_t ATMF:1;
	 	 uint8_t ATMS:1;
	 	 uint8_t ATME:1;
	 } SC_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t SCTRIM:8;
	 } ATCVH_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t SCTRIM:8;
	 } ATCVL_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t OSCSEL:1;
	 	 uint8_t Reserved0:5;
	 	 uint8_t Reserved1:2;
	 } C7_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t Reserved0:1;
	 	 uint8_t Reserved1:4;
	 	 uint8_t Reserved2:1;
	 	 uint8_t LOLRE:1;
	 	 uint8_t Reserved3:1;
	 } C8_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t Reserved0:1;
	 	 uint8_t Reserved1:3;
	 	 uint8_t Reserved2:2;
	 	 uint8_t Reserved3:2;
	 } C9_Type;

	 typedef struct __attribute__((packed)){
	 	 uint8_t Reserved0:4;
	 	 uint8_t Reserved1:4;
	 } C10_Type;

	 typedef struct __attribute__((packed)){
	 	__IO C1_Type C1;
	 	__IO C2_Type C2;
	 	__IO C3_Type C3;
	 	__IO C4_Type C4;
	 	__IO C5_Type C5;
	 	__IO C6_Type C6;
	 	__I S_Type S;
	 	uint8_t PAD0[1];
	 	__IO SC_Type SC;
	 	uint8_t PAD1[1];
	 	__IO ATCVH_Type ATCVH;
	 	__IO ATCVL_Type ATCVL;
	 	__IO C7_Type C7;
	 	__IO C8_Type C8;
	 	__I C9_Type C9;
	 	__I C10_Type C10;
	 } MCG_Type;

}

/*Modes of operation*/
typedef enum{FEI, FBI, FEE, FBE, PBE, PEE, BLPI, BLPE, INVALID} MODE_OF_OPERATION;

using namespace mcg_namespace;

class MCG{
	MCG_Type *mcg;
	MODE_OF_OPERATION get_mode_of_operation(){
		switch(mcg->S.CLKST){
		case 0: //F or P engaged
			if (mcg->S.IREFST && ~(mcg->S.PLLST)) return FEI;
			else if (~(mcg->S.IREFST) && ~(mcg->S.PLLST)) return FEE;
			else if (~(mcg->S.IREFST) && mcg->S.PLLST) return PEE;
			break;
		case 1: // Bypassed internal
			if (mcg->S.IREFST && ~(mcg->S.PLLST) && ~(mcg->C2.LP)) return FBI;
			else if (mcg->S.IREFST && mcg->C2.LP) return BLPI;
			break;
		case 2: // Bypassed external
			if (~(mcg->S.IREFST) && ~(mcg->C2.LP) && ~(mcg->S.PLLST)) return FBE;
			else if (~(mcg->S.IREFST) && ~(mcg->C2.LP) && mcg->S.PLLST) return PBE;
			else if (~(mcg->S.IREFST) && mcg->C2.LP) return BLPE;
			break;
		case 3: // Invalid
			break;
		}
		return INVALID;
	}
public:
	MCG(unsigned int MODULE_BASE){
		mcg = (MCG_Type *)MODULE_BASE;
	}
	void set_drst_drs(uint8_t drst_drs){
		mcg->C4.DRST_DRS = drst_drs;
	}
	void set_dmx32(uint8_t dmx32){
		mcg->C4.DMX32 = dmx32;
	}

	friend void SIM::set_outdiv1(uint8_t div1);
	friend void SIM::set_outdiv4(uint8_t div1);

	void fei_to_pee(void){
		if (get_mode_of_operation() != FEI){
			return;
		}

		//switch to FBE
		mcg->C2.RANGE0 = 0b10u; //very high frequency range selected for the crystal oscillator
		mcg->C2.HGO0 = 0b1u; //high-gain operation
		mcg->C2.EREFS0 = 0b1u; //crystal is being used
		mcg->C1.FRDIV = 0b011u;  //In FBE mode, it is not required to meet this range, but it is recommended in the cases when trying to enter a FLL mode from FBE
		mcg->C1.IREFS = 0b0u;	//External reference clock is selected for FLL(This is a constraint)
		mcg->C1.CLKS = 0b10u;	//External reference clock is selected bypassing FLL and PLL

		while(mcg->S.OSCINIT0 != 0b1u){;;}
		while(mcg->S.IREFST != 0b0u){;;}
		//wait until external clock is selected bypassing FLL and PLL
		while(mcg->S.CLKST != 0b10u){;;}

		//enable PLL
		mcg->C5.PRDIV0 = 0b1u; //PLL divide factor 2
		mcg->C6.VDIV0 = 0; // PLL multiply factor 24
		mcg->C6.PLLS = 0b1u; //select PLL from PLL/FLL MUX
		mcg->C1.CLKS = 0b00u; //select PLL as clock source

		//wait until PLL is clock source
		while(mcg->S.PLLST != 0b1u){;;}
		while(mcg->S.LOCK0 != 0b1u){;;}
		while(mcg->S.CLKST != 0b11u){;;}
	}
};

#endif
