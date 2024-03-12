/*
 * ADC_interface.h
 *
 * Created: 3/4/2024 11:31:08 AM
 *  Author: Tarek Alaa
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

typedef enum
{
	ADC_AREF,
	ADC_AVCC,
	ADC_INTERNALVREF = 3 //2.56v
}ADC_VREF_t;

typedef enum
{
	ADC_CHANNEL0,
	ADC_CHANNEL1,
	ADC_CHANNEL2,
	ADC_CHANNEL3,
	ADC_CHANNEL4,
	ADC_CHANNEL5,
	ADC_CHANNEL6,
	ADC_CHANNEL7
}ADC_CHANNELNUM_t;

typedef enum
{
	ADC_ADJUSTRIGHT,
	ADC_ADJUSTLEFT
}ADC_ADJUSTRESULT_t;

typedef enum
{
	ADC_2_PRESCALER,
	ADC_4_PRESCALER = 2,
	ADC_8_PRESCALER,
	ADC_16_PRESCALER,
	ADC_32_PRESCALER,
	ADC_64_PRESCALER,
	ADC_128_PRESCALER,
}ADC_PRESCALER_t;

typedef enum
{
	ADC_10_BITS,
	ADC_8_BITS
}ADC_RESOLUTION_t;


typedef struct
{
	ADC_VREF_t			enumVREF;
	ADC_CHANNELNUM_t	enumChannelNum;
	ADC_ADJUSTRESULT_t	enumAdjustResult;
	ADC_PRESCALER_t		enumPrescaler;
}ADC_CONFIG_t;

void ADC_voidInit(ADC_CONFIG_t copy_strConfig);
void ADC_voidGetDigitalValue(ADC_CHANNELNUM_t copy_enumChannelNum, u16 *copy_pu16Value);


#endif /* ADC_INTERFACE_H_ */