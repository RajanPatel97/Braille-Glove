#include "sdk_config.h"
#include "SEGGER_RTT.h"
#include "bbs_logger.h"

/**
 *	Function to log a braille character (lower 6 bits)
 *	@input 8 bit integer containing 6 braille bits
 */

void log_braille_char(uint8_t in) {
	SEGGER_RTT_printf(0,"braille: ");
	
	SEGGER_RTT_printf(0,"%d",(in) & (1<<5));
	SEGGER_RTT_printf(0,"%d",(in) & (1<<4));
	SEGGER_RTT_printf(0,"%d",(in) & (1<<3));
	SEGGER_RTT_printf(0,"%d",(in) & (1<<2));
	SEGGER_RTT_printf(0,"%d",(in) & (1<<1));
	SEGGER_RTT_printf(0,"%d",(in) & (1<<0));
	
	SEGGER_RTT_printf(0,"\r\n");
	return;
}

/**
 *	Function to log a string
 *	@input pointer to array of characters
 *	@input length of the string
 */

void log_string(uint8_t * p_string, uint16_t length) {
	SEGGER_RTT_printf(0,"STRING: ");
	int i = 0;
	for(i=0;i<length;i++) {
		SEGGER_RTT_printf(0,"%c",p_string[i]);
	}
	SEGGER_RTT_printf(0,"\r\n");
	return;
}
