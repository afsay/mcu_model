#ifndef PINS_H
#define PINS_H

typedef enum {
	PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7,
	PIN8, PIN9, PIN10, PIN11, PIN12, PIN13, PIN14, PIN15,
	PIN16, PIN17, PIN18, PIN19, PIN20, PIN21, PIN22, PIN23,
	PIN24, PIN25, PIN26, PIN27, PIN28, PIN29, PIN30, PIN31
} PIN_NUM;

typedef enum {
	PIN0_MASK=0x00000001,
	PIN1_MASK=0x00000002,
	PIN2_MASK=0x00000004,
	PIN3_MASK=0x00000008,
	PIN4_MASK=0x00000010,
	PIN5_MASK=0x00000020,
	PIN6_MASK=0x00000040,
	PIN7_MASK=0x00000080,
	PIN8_MASK=0x00000100,
	PIN9_MASK=0x00000200,
	PIN10_MASK=0x00000400,
	PIN11_MASK=0x00000800,
	PIN12_MASK=0x00001000,
	PIN13_MASK=0x00002000,
	PIN14_MASK=0x00004000,
	PIN15_MASK=0x00008000,
	PIN16_MASK=0x00010000,
	PIN17_MASK=0x00020000,
	PIN18_MASK=0x00040000,
	PIN19_MASK=0x00080000,
	PIN20_MASK=0x00100000,
	PIN21_MASK=0x00200000,
	PIN22_MASK=0x00400000,
	PIN23_MASK=0x00800000,
	PIN24_MASK=0x01000000,
	PIN25_MASK=0x02000000,
	PIN26_MASK=0x04000000,
	PIN27_MASK=0x08000000,
	PIN28_MASK=0x10000000,
	PIN29_MASK=0x20000000,
	PIN30_MASK=0x40000000,
	PIN31_MASK=0x80000000
} PIN_MASK;

#endif
