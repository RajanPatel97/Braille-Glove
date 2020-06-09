#include "sdk_config.h"
#include <stdint.h>

#define LOWER_CASE_MOD 	48
#define UPPER_CASE_MOD 	32
#define NUMPUNC_MOD			60

#define LOWER_CASE_OFFSET 97
#define UPPER_CASE_OFFSET 65
#define NUMPUNC_OFFSET		33

#define IS_LOWER(c)			((c)>=(97)&&(c)<=(122))
#define IS_CAPITAL(c)		((c)>=(65)&&(c)<=(90))
#define IS_NUMPUNC(c)		((c)>=(33)&&(c)<=(63))

extern uint8_t char_2_braille(char character);

extern void modifier_parser(uint8_t * p_string, uint16_t string_length, uint8_t * p_mod);

extern uint8_t braille_2_char(uint8_t braille, uint8_t modifier);