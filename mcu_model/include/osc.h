#ifndef OSC_H
#define OSC_H

#include <stdint.h>
#include "MKL46Z4_bsp.h"
#include "pins.h"

namespace osc_namespace {
typedef struct __attribute__((packed)){
	uint8_t SC16P:1;
	uint8_t SC8P:1;
	uint8_t SC4P:1;
	uint8_t SC2P:1;
	const uint8_t Reserved0:1;
	uint8_t EREFSTEN:1;
	const uint8_t Reserved1:1;
	uint8_t ERCLKEN:1;
} CR_Type;

typedef struct __attribute__((packed)){
	__IO CR_Type CR;
} OSC_Type;

}

using namespace osc_namespace;

class OSC{
	OSC_Type *osc;
public:
	OSC(unsigned int MODULE_BASE){
		osc = (OSC_Type *)MODULE_BASE;
	}
	void enable_external_osc(bool value){
		osc->CR.ERCLKEN = value;
	}
};
#endif
