
#include "sdk_config.h"
#include "nrf_drv_gpiote.h"
#include "SEGGER_RTT.h"
#include "fifo.h"

/**
 *	Function to initialise the buffers
 */
uint32_t add_fifo(buffer_t * p_fifo, braille_char * buffer)
{	

		p_fifo->p_start = buffer;
		p_fifo->buf_size = 0;
		p_fifo->read_pos = 0;
		p_fifo->write_pos = 0;

		return NRF_SUCCESS;
}

/** Function to put byte into fifo buffer
 *	@input 	byte of data
 * 	@output error code
 */
uint32_t fifo_put(buffer_t * p_fifo, braille_char character) {
	//check the buffer size hasn't exceeded it's limit
	if(p_fifo->buf_size >= BUFF_SIZE) {
		return BUFF_FULL;
	}

	//write character to that position
	*(p_fifo->p_start + (uint8_t)p_fifo->write_pos) = character;	
	
	//increment buffer size
	p_fifo->buf_size++;
	
	//loopback if it's at the end of the buffer
	if(p_fifo->write_pos==BUFF_SIZE-1) {
		p_fifo->write_pos = 0;
	}
	else {
		p_fifo->write_pos++;
	}
	
	return NRF_SUCCESS;
}

/** Function to get byte from fifo buffer
 *	@input 	pointer to data that will be pulled from buffer
 * 	@output error code
 */
uint32_t fifo_get(buffer_t * p_fifo, braille_char * p_character) {
	//If the buffer is empty, you can't read
	if(p_fifo->buf_size == 0) {
		return BUFF_EMPTY;
	}
	
	//decrement current buffer size
	p_fifo->buf_size--;
	
	//get character from the buffer
	*p_character = *(p_fifo->p_start + (uint8_t)p_fifo->read_pos);
	
	//loops back if it's at the end of the buffer.
	if(p_fifo->read_pos == BUFF_SIZE-1) {
		p_fifo->read_pos = 0;
	}
	else {
		p_fifo->read_pos++;
	}
	
	return NRF_SUCCESS;
}

/** Function to clear buffer (reset read and write positions)
 *
 */
 
uint32_t fifo_clear(buffer_t * p_fifo) {
	
	//just sets the write position to read's and clears buffer size
	p_fifo->write_pos = p_fifo->read_pos;
	p_fifo->buf_size = 0;
	
	return NRF_SUCCESS;
}
