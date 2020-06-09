#include "sdk_config.h"
#include "bbs_gpio.h"
#include "bbs.h"


uint32_t add_gpio_output(void) {
	
	nrf_gpio_cfg_output(BRAILLE_MOTOR_0);
	nrf_gpio_cfg_output(BRAILLE_MOTOR_1);
	nrf_gpio_cfg_output(BRAILLE_MOTOR_2);
	nrf_gpio_cfg_output(BRAILLE_MOTOR_3);
	nrf_gpio_cfg_output(BRAILLE_MOTOR_4);
	nrf_gpio_cfg_output(BRAILLE_MOTOR_5);
	
	return NRF_SUCCSESS;
}

uint32_t add_gpio_message_input(void) {
	
	nrf_gpio_cfg_input(BRAILLE_INPUT_0,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(BRAILLE_INPUT_1,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(BRAILLE_INPUT_2,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(BRAILLE_INPUT_3,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(BRAILLE_INPUT_4,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(BRAILLE_INPUT_5,NRF_GPIO_PIN_PULLUP);
	
	return NRF_SUCCSESS;
}

uint32_t clear_gpio_output(void) {
	
	nrf_gpio_pin_clear(BRAILLE_MOTOR_0);
	nrf_gpio_pin_clear(BRAILLE_MOTOR_1);
	nrf_gpio_pin_clear(BRAILLE_MOTOR_2);
	nrf_gpio_pin_clear(BRAILLE_MOTOR_3);
	nrf_gpio_pin_clear(BRAILLE_MOTOR_4);
	nrf_gpio_pin_clear(BRAILLE_MOTOR_5);
	
	return NRF_SUCCSESS;
}


/**
 *	Function to set pin outputs
 *	@input pointer to character for pin inputs
 *	@output error code
 */

uint32_t set_output(uint8_t * p_char) {
	uint32_t err_code;
	SEGGER_RTT_printf(0,"Writing to ouptut (single char)");
	
	//sending bit 0 to motor 0
	if(BIT_CHECK(*p_char,0)) {
		nrf_gpio_pin_set(BRAILLE_MOTOR_0);
	}
	else {
		nrf_gpio_pin_clear(BRAILLE_MOTOR_0);
	}
	
	//sending bit 1 to motor 1
	if(BIT_CHECK(*p_char,1)) {
		nrf_gpio_pin_set(BRAILLE_MOTOR_1);
	}
	else {
		nrf_gpio_pin_clear(BRAILLE_MOTOR_1);
	}
		
	//sending bit 2 to motor 2
	if(BIT_CHECK(*p_char,2)) {
		nrf_gpio_pin_set(BRAILLE_MOTOR_2);
	}
	else {
		nrf_gpio_pin_clear(BRAILLE_MOTOR_2);
	}
		
	//sending bit 3 to motor 3
	if(BIT_CHECK(*p_char,3)) {
		nrf_gpio_pin_set(BRAILLE_MOTOR_3);
	}
	else {
		nrf_gpio_pin_clear(BRAILLE_MOTOR_3);
	}
	
	//sending bit 4 to motor 4
	if(BIT_CHECK(*p_char,4)) {
		nrf_gpio_pin_set(BRAILLE_MOTOR_4);
	}
	else {
		nrf_gpio_pin_clear(BRAILLE_MOTOR_4);
	}
		
	//sending bit 5 to motor 5
	if(BIT_CHECK(*p_char,5)) {
		nrf_gpio_pin_set(BRAILLE_MOTOR_5);
	}
	else {
		nrf_gpio_pin_clear(BRAILLE_MOTOR_5);
	}

	//debug message
	SEGGER_RTT_printf(0,"Motor output, ");
	log_braille_char(*p_char);
	
	return NRF_SUCCESS;
}

void bbs_message_gpio_init(void) {
	
	return;
}

void message_input(void) {
	
	return;
}
