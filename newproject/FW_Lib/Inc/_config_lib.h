#ifndef _CONFIG_LIB_H_
#define _CONFIG_LIB_H_

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define NON_FPU               // Uncomment this define if MCU doesnot has FPU (FLoating point unit)

/*
// Enable or disable peripheral
// Uncomment to enable peripheral
*/
#define ENABLE_ISR
#define ENABLE_TIMER
#define ENABLE_GPIO
#define ENABLE_ADC
#define ENABLE_PWM
#define ENABLE_UART
#define ENABLE_SPI
// #define ENABLE_CAN
#define ENABLE_DAC
#define ENABLE_ECAP

#endif /* _CONFIG_LIB_H_ */



