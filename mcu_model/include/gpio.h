#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include "MKL46Z4_bsp.h"
#include "pins.h"

typedef struct {
	__IO uint32_t PDOR;                              /**< Port Data Output Register, offset: 0x0 */
	__O  uint32_t PSOR;                              /**< Port Set Output Register, offset: 0x4 */
	__O  uint32_t PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
	__O  uint32_t PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
	__I  uint32_t PDIR;                              /**< Port Data Input Register, offset: 0x10 */
	__IO uint32_t PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
} GPIO_t;

typedef enum {INPUT, OUTPUT} DIRECTION;

class GPIO{
	GPIO_t *gpio;

	public:
		GPIO(unsigned int GPIO_BASE){
			gpio = (GPIO_t *)GPIO_BASE;
		}
		void write_pin(PIN_MASK pin, bool value);
		void set_ping(PIN_MASK pin);
		void clear_pin(PIN_MASK pin);
		void inline toggle_pin(uint32_t pin_mask){
			this->gpio->PTOR = pin_mask;
		}
		bool read_pin(PIN_MASK pin);
		void set_direction(PIN_MASK pin, DIRECTION dir);
	};

#endif

