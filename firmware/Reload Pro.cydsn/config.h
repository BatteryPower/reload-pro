/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <project.h>

#define UI_TASK_FREQUENCY 20 // hz

// How much does one encoder detent adjust the current?
#define CURRENT_LOWRANGE_STEP 1000 // 1mA
#define CURRENT_FULLRANGE_STEP 20000 // 20mA

// Where do we switch from the low current range to the high range?
#define CURRENT_LOWRANGE_THRESHOLD 250000 // 250mA

// What's the maximum current?
#define CURRENT_MAX 6000000 // 6A

#define DEFAULT_DAC_LOW_GAIN 		1008 	// 2.4uA over 21 ohms, 0.05 ohm shunt = 1.008mA per count
#define DEFAULT_DAC_HIGH_GAIN 		23520	// 2.4uA over 490 ohms, 0.05 ohm shunt = 23.520mA per count
#define DEFAULT_OPAMP_OFFSET_TRIM	0x20
#define DEFAULT_DAC_OFFSET			0
#define DEFAULT_ADC_CURRENT_OFFSET	0
#define DEFAULT_ADC_CURRENT_GAIN 	625		// 1.024 volts / (1 microamp * 0.05 ohms) / 2048 / 16 = 625 microamps per count
#define DEFAULT_ADC_VOLTAGE_OFFSET	0		
#define DEFAULT_ADC_VOLTAGE_GAIN	1226	// 1.024 volts / (1 microvolt * (5.23 kiloohms / 205.23 kiloohms)) / 2048 / 16 = 1226 microvolts per count


typedef struct {
	int current_setpoint;
	int8 current_range;
} state_t;

extern state_t state;

typedef struct {
	int dac_low_gain;		// Microamps per DAC count, low range
	int dac_high_gain; 		// Microamps per DAC count, high range
	int dac_offset;			// DAC offset value in microamps
	int opamp_offset_trim;	// Offset trim value for opamp
	
	int adc_current_offset;	// ADC current reading offset in counts
	int adc_current_gain;	// Microamps per ADC count
	
	int adc_voltage_offset;	// ADC voltage reading offset in counts
	int adc_voltage_gain;	// Microvolts per ADC count
} settings_t;

extern volatile settings_t settings;

void set_current(int setpoint);
int get_current_setpoint();
int get_current_usage();
int get_voltage();

void setup();

/* [] END OF FILE */