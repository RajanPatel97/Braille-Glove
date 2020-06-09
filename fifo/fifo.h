#ifndef _fifo_h
#define _fifo_h

#include "sdk_config.h"
#include "nrf_drv_gpiote.h"
#include "SEGGER_RTT.h"

#define BUFF_SIZE 255
#define BUFF_EMPTY 1
#define BUFF_FULL 2


/**
 * Structure of the fifo implimentation
 * TODO test the actual implimentation of this
 */

typedef uint8_t braille_char;

typedef struct
{
	uint8_t * 	p_start;
	uint32_t 		buf_size;
	uint32_t 		read_pos;
	uint32_t 		write_pos;
} buffer_t;

extern uint32_t add_fifo(buffer_t * p_fifo, braille_char * buffer);

extern uint32_t fifo_put(buffer_t * p_fifo, braille_char character);

extern uint32_t fifo_get(buffer_t * p_fifo, braille_char * p_character);

extern uint32_t fifo_clear(buffer_t * p_fifo);

#endif // !defined(_fifo_h)