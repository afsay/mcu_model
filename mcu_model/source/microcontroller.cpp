#include "microcontroller.h"
#include "MKL46Z4_bsp.h"

MicroController::MicroController(void){
	PortB = new PORT(PORTB_BASE);
	PortC = new PORT(PORTC_BASE);
	PortD = new PORT(PORTD_BASE);
	PortE = new PORT(PORTE_BASE);

	GpioB = new GPIO(GPIOB_BASE);
	GpioC = new GPIO(GPIOC_BASE);
	GpioD = new GPIO(GPIOD_BASE);
	GpioE = new GPIO(GPIOE_BASE);
}

/*
 * 24.5.3.1 Example 1: Moving from FEI to PEE mode: External Crystal = 4 MHz, MCGOUTCLK frequency = 48 MHz
 */
void MicroController::set_external_48mhz_clock(void){
	Osc.enable_external_osc(true);
	Sim.set_outdiv1(1); //divide 96 mhz PLL output to 2
	Sim.set_outdiv4(1);
	Mcg.fei_to_pee();
}

UART0 MicroController::Uart0 = UART0(UART0_BASE);
PORT MicroController::PortA = PORT(PORTA_BASE);
GPIO MicroController::GpioA = GPIO(GPIOA_BASE);
SIM MicroController::Sim = SIM(SIM_BASE);
MCG MicroController::Mcg = MCG(MCG_BASE);
OSC MicroController::Osc = OSC(OSC_BASE);
