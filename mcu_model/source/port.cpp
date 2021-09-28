#include "port.h"
#include "sim.h"
bool PORT::interrupt_status_flag(PIN_NUM pin){
	return this->port->PCR[pin].ISF;
}

void PORT::clear_interrupt_status_flag(PIN_NUM pin){
	this->port->PCR[pin].ISF = 1;
}

void PORT::interrupt_configuration(PIN_NUM pin, PIN_INT_CONFIG irqc){
	this->port->PCR[pin].IRQC = irqc;
}

void PORT::pin_mux_control(PIN_NUM pin, PIN_MUX_CONFG mux){
	port->PCR[pin].MUX = mux;
}

void PORT::set_drive_strength(PIN_NUM pin, DRIVE_STRENGTH dse){
	this->port->PCR[pin].DSE = dse;
}

DRIVE_STRENGTH PORT::get_drive_strength(PIN_NUM pin){
	return (DRIVE_STRENGTH) this->port->PCR[pin].DSE;
}

void PORT::set_passive_filter(PIN_NUM pin, PASSIVE_FILTER pfe){
	this->port->PCR[pin].PFE = pfe;
}

PASSIVE_FILTER PORT::get_passive_filter(PIN_NUM pin){
	return (PASSIVE_FILTER) this->port->PCR[pin].PFE;
}

void PORT::set_slew_rate(PIN_NUM pin, SLEW_RATE sre){
	this->port->PCR[pin].SRE  = sre;
}

SLEW_RATE PORT::get_slew_rate(PIN_NUM pin){
	return (SLEW_RATE) this->port->PCR[pin].SRE;
}

void PORT::set_pull(PIN_NUM pin, PULL pe){
	this->port->PCR[pin].PE = pe;
}

PULL PORT::get_pull(PIN_NUM pin){
	return (PULL) this->port->PCR[pin].PE;
}

void PORT::set_pull_select(PIN_NUM pin, PULL_SELECT ps){
	this->port->PCR[pin].PS = ps;
}

PULL_SELECT PORT::get_pull_select(PIN_NUM pin){
	return (PULL_SELECT) this->port->PCR[pin].PS;
}
