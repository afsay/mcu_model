#ifndef MKL46Z4_BSP_H
#define MKL46Z4_BSP_H

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_IRQn                    = 0,                /**< DMA channel 0 transfer complete and error interrupt */
  DMA1_IRQn                    = 1,                /**< DMA channel 1 transfer complete and error interrupt */
  DMA2_IRQn                    = 2,                /**< DMA channel 2 transfer complete and error interrupt */
  DMA3_IRQn                    = 3,                /**< DMA channel 3 transfer complete and error interrupt */
  Reserved20_IRQn              = 4,                /**< Reserved interrupt */
  FTFA_IRQn                    = 5,                /**< FTFA command complete and read collision */
  LVD_LVW_IRQn                 = 6,                /**< Low-voltage detect, low-voltage warning */
  LLWU_IRQn                    = 7,                /**< Low Leakage Wakeup */
  I2C0_IRQn                    = 8,                /**< I2C0 interrupt */
  I2C1_IRQn                    = 9,                /**< I2C1 interrupt */
  SPI0_IRQn                    = 10,               /**< SPI0 single interrupt vector for all sources */
  SPI1_IRQn                    = 11,               /**< SPI1 single interrupt vector for all sources */
  UART0_IRQn                   = 12,               /**< UART0 status and error */
  UART1_IRQn                   = 13,               /**< UART1 status and error */
  UART2_IRQn                   = 14,               /**< UART2 status and error */
  ADC0_IRQn                    = 15,               /**< ADC0 interrupt */
  CMP0_IRQn                    = 16,               /**< CMP0 interrupt */
  TPM0_IRQn                    = 17,               /**< TPM0 single interrupt vector for all sources */
  TPM1_IRQn                    = 18,               /**< TPM1 single interrupt vector for all sources */
  TPM2_IRQn                    = 19,               /**< TPM2 single interrupt vector for all sources */
  RTC_IRQn                     = 20,               /**< RTC alarm interrupt */
  RTC_Seconds_IRQn             = 21,               /**< RTC seconds interrupt */
  PIT_IRQn                     = 22,               /**< PIT single interrupt vector for all channels */
  I2S0_IRQn                    = 23,               /**< I2S0 Single interrupt vector for all sources */
  USB0_IRQn                    = 24,               /**< USB0 OTG */
  DAC0_IRQn                    = 25,               /**< DAC0 interrupt */
  TSI0_IRQn                    = 26,               /**< TSI0 interrupt */
  MCG_IRQn                     = 27,               /**< MCG interrupt */
  LPTMR0_IRQn                  = 28,               /**< LPTMR0 interrupt */
  LCD_IRQn                     = 29,               /**< Segment LCD interrupt */
  PORTA_IRQn                   = 30,               /**< PORTA pin detect */
  PORTC_PORTD_IRQn             = 31                /**< Single interrupt vector for PORTC and PORTD pin detect */
} IRQn_Type;

#define __CM0PLUS_REV                  0x0000    /**< Core revision r0p0 */
#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT                 1         /**< Defines if VTOR is present or not */
#define __NVIC_PRIO_BITS               2         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */

#include "core_cm0plus.h"

#define PORTA_BASE                               (0x40049000u)
#define PORTB_BASE                               (0x4004A000u)
#define PORTC_BASE                               (0x4004B000u)
#define PORTD_BASE                               (0x4004C000u)
#define PORTE_BASE                               (0x4004D000u)

#define GPIOA_BASE                               (0x400FF000u)
#define GPIOB_BASE                               (0x400FF040u)
#define GPIOC_BASE                               (0x400FF080u)
#define GPIOD_BASE                               (0x400FF0C0u)
#define GPIOE_BASE                               (0x400FF100u)

#define SIM_BASE                                 (0x40047000u)

#define MCG_BASE                                 (0x40064000u)
#define OSC_BASE                                 (0x40065000u)

#define UART0_BASE 								 (0X4006A000u)


#endif
