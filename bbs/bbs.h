/** Braille Boys Hardware drivers and general device structures
*/
/* NEXT PERSON TO TOUCH THE FUCKING INCLUDE GUARD, *
 * I EAT YOUR FUCKING FIRSTBORN - henry            */
#ifndef _bbs_h
#define _bbs_h

#include "sdk_config.h"
#include "nrf_drv_gpiote.h"
#include "SEGGER_RTT.h"
#include "fifo.h"
#include "ble_nus.h"
#include "bbs_gpio.h"

#define BRAILLE_MOTOR_0			1		//pin assignment for motor 0
#define BRAILLE_MOTOR_1			2		//pin assignment for motor 1
#define BRAILLE_MOTOR_2			3		//pin assignment for motor 2
#define BRAILLE_MOTOR_3			4		//pin assignment for motor 3
#define BRAILLE_MOTOR_4			5		//pin assignment for motor 4
#define BRAILLE_MOTOR_5			6		//pin assignment for motor 5

#define BRAILLE_INPUT_0 		8		//pin assignment for input of bit 0 for braille character
#define BRAILLE_INPUT_1 		9		//pin assignment for input of bit 1 for braille character
#define BRAILLE_INPUT_2 		10	//pin assignment for input of bit 2 for braille character
#define BRAILLE_INPUT_3 		11	//pin assignment for input of bit 3 for braille character
#define BRAILLE_INPUT_4 		12	//pin assignment for input of bit 4 for braille character
#define BRAILLE_INPUT_5 		13	//pin assignment for input of bit 5 for braille character

#define CONTROL_INPUT_0 		17	//pin assignment for control button 0
#define CONTROL_INPUT_1 		18	//pin assignment for control button 1
#define CONTROL_INPUT_2 		19	//pin assignment for control button 2
#define CONTROL_INPUT_3 		20	//pin assignment for control button 3

#define MSG_BIT_0 					0
#define MSG_BIT_1 					1
#define MSG_BIT_2 					2
#define MSG_BIT_3 					3
#define MSG_BIT_4 					4
#define MSG_BIT_5 					5

#define TEMP_MASK						6
#define RXTX_MASK						7
#define MSG_BIT_MASK				63

#define BIT_CLEAR(val,pos)	((val) &= ~((1)<<(pos)))
#define BIT_SET(val,pos)		((val) |= ((1)<<(pos)))

#define BIT_CHECK(val,pos) 	((val) & 	((1)<<(pos)))

//global nordic uart service type
extern ble_nus_t                        m_nus; 

/**
	typedef for a braille character
	we'll use 8 bits for now
 */ 
typedef uint8_t braille_char;


/**
 * Global fifo structures
 */
extern buffer_t * m_raw_fifo;
extern buffer_t * m_braille_fifo;

/**
 * Static memory initialisation for buffers
 */
extern uint8_t	raw_buf[BUFF_SIZE];
extern uint8_t 	braille_buf[BUFF_SIZE];


/**
 * List of function references
*/
extern void pin_message_event_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action);

extern void pin_control_event_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action);

uint32_t add_input_pins(void);

uint32_t add_output_pins(void);

uint32_t clear_output(void);

uint32_t set_output(uint8_t * p_char);

extern void bluetooth_receive(uint8_t * p_data, uint16_t length);

void rxtx_toggle(void);

extern void bbs_init(void);

#endif