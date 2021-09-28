#include "gpio.h"

void GPIO::write_pin(PIN_MASK pin, bool value){
	if (value == true)
		this->gpio->PDOR |= pin;
	else
		this->gpio->PDOR &= ~pin;
}

void GPIO::set_ping(PIN_MASK pin){
	this->gpio->PSOR = pin;
}

void GPIO::clear_pin(PIN_MASK pin){
	this->gpio->PCOR = pin;
}



bool GPIO::read_pin(PIN_MASK pin){
	return (this->gpio->PDIR & pin) != 0;
}

void GPIO::set_direction(PIN_MASK pin, DIRECTION dir){
	if (dir == INPUT)
		this->gpio->PDDR &= ~pin;
	else
		this->gpio->PDDR |= pin;
}
