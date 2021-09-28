#ifndef MICROCONTROLLER_H
#define MICROCONTROLLER_H

#include "port.h"
#include "gpio.h"
#include "sim.h"
#include "mcg.h"
#include "osc.h"
#include "uart.h"

class MicroController{
	public:
		MicroController();
		PORT *PortB, *PortC, *PortD, *PortE;
		GPIO *GpioB, *GpioC, *GpioD, *GpioE;
		static SIM Sim;
		static MCG Mcg;
		static OSC Osc;
		static UART0 Uart0;
		static PORT PortA;
		static GPIO GpioA;

		static void set_external_48mhz_clock(void);
};

#endif
