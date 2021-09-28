#ifndef PORT_H
#define PORT_H

#include <stdint.h>
#include "MKL46Z4_bsp.h"
#include "pins.h"

typedef struct{
		uint8_t PS:1;
		uint8_t PE:1;
		uint8_t SRE:1;
		uint8_t RES0:1;
		uint8_t PFE:1;
		uint8_t RES1:1;
		uint8_t DSE:1;
		uint8_t RES2:1;
		uint8_t MUX:3;
		uint8_t RES3:5;
		uint8_t IRQC:4;
		uint8_t RES4:4;
		uint8_t ISF:1;
		uint8_t RES5:7;
}PCR_Type;

typedef struct {
	__IO PCR_Type PCR[32];                           /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
	__O  uint32_t GPCLR;                             /**< Global Pin Control Low Register, offset: 0x80 */
	__O  uint32_t GPCHR;                             /**< Global Pin Control High Register, offset: 0x84 */
	     uint8_t  RESERVED_0[24];
	__IO uint32_t ISFR;                              /**< Interrupt Status Flag Register, offset: 0xA0 */
} PORT_t;

typedef enum {	INT_DMA_DISABLED = 0b0000,
				DMA_RE = 0b0001,
				DMA_FE = 0b0010,
				DMA_EE = 0b0011,
				INT_LZ = 0b1000,
				INT_RE = 0b1001,
				INT_FE = 0b1010,
				INT_EE = 0b1011,
				INT_LO = 0b1100 } PIN_INT_CONFIG;

typedef enum {	PIN_DISABLED,
				GPIO_PIN,
				ALT2_PIN,
				ALT3_PIN,
				ALT4_PIN,
				ALT5_PIN,
				ALT6_PIN,
				ALT7_PIN } PIN_MUX_CONFG;

typedef enum {LOW_DS, HIGH_DS} DRIVE_STRENGTH;
typedef enum {DISABLE_PF, ENABLE_PF} PASSIVE_FILTER;
typedef enum {DISABLE_P, ENABLE_P} PULL;
typedef enum {FAST_SR, SLOW_SR} SLEW_RATE;
typedef enum {DOWN_PS, UP_PS} PULL_SELECT;

class PORT{
	PORT_t *port;

	public:
		PORT(unsigned int PORT_BASE){
			port = ((PORT_t *) PORT_BASE);
		}
		bool interrupt_status_flag(PIN_NUM pin);
		void clear_interrupt_status_flag(PIN_NUM pin);
		void interrupt_configuration(PIN_NUM pin, PIN_INT_CONFIG irqc);
		void pin_mux_control(PIN_NUM pin, PIN_MUX_CONFG mux);
		void set_drive_strength(PIN_NUM pin, DRIVE_STRENGTH dse);
		DRIVE_STRENGTH get_drive_strength(PIN_NUM pin);
		void set_passive_filter(PIN_NUM pin, PASSIVE_FILTER pfe);
		PASSIVE_FILTER get_passive_filter(PIN_NUM pin);
		void set_slew_rate(PIN_NUM pin, SLEW_RATE sre);
		SLEW_RATE get_slew_rate(PIN_NUM pin);
		void set_pull(PIN_NUM pin, PULL pe);
		PULL get_pull(PIN_NUM pin);
		void set_pull_select(PIN_NUM pin, PULL_SELECT ps);
		PULL_SELECT get_pull_select(PIN_NUM pin);
};

#endif
