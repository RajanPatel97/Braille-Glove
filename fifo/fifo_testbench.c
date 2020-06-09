#include "fifo.h"
#include "fifo.c"

buffer_t * p_test;
braille_char test_buffer[BUFF_SIZE+1];

int main() {
	uint32_t err_code = add_fifo(p_test, &test_buffer[0]);
	
	if(err_code == NRF_SUCCESS) {
		printf("added fifo buffer");
	}
	else {
		return 0;
	}
	
	return 0;
}