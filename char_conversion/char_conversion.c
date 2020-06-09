/*
Module to convert Braille to Characters
-Uses 

notes
-Needs to stay in flash

 to look up a character's corresponding braille value,
 the character can be used as an array index with
 an offset subtracted.
*/

#include "sdk_config.h"
#include "char_conversion.h"
#include <stdint.h>

void modifier_parser(uint8_t * p_string, uint16_t string_length, uint8_t * p_mod) {
	int index = 0;
	uint8_t temp_mod = LOWER_CASE_MOD;
	
	//goes to the end of the message
	while(index<string_length) {
		//set modifier to lower case as default
		temp_mod = LOWER_CASE_MOD;
		
		if(IS_CAPITAL(p_string[index])) {
			temp_mod = UPPER_CASE_MOD;
		}	
		//if there is a number/punctuation, set to the numpunc modifier
		if(IS_NUMPUNC(p_string[index])) {
			temp_mod = NUMPUNC_MOD;
		}
		
		p_mod[index] = temp_mod;
		index++;
	}
	return;
}




uint8_t char_2_braille(char character){
	
	static const uint8_t lower_case_lookup[26] = {
		1, 3, 9, 25, 17, 11, 27, 19, 10, 		// a, b, c, d, e, f, g, h, i
		26,	5, 7, 13, 29, 21, 15, 31, 23, 	// j, k, l, m, n, o, p, q, r
		14,	30, 37, 39, 58, 45, 61, 53			// s, t, u, v, w, x, y, z			
	};
	
	static const uint8_t upper_case_lookup[26] = {
		1, 3, 9, 25, 17, 11, 27, 19, 10, 		// A, B, C, D, E, F, G, H, I
		26,	5, 7, 13, 29, 21, 15, 31, 23, 	// J, K, L, M, N, O, P, Q, R
		14,	30, 37, 39, 58, 45, 61, 53			// S, T, U, V, W, X, Y, Z			
	};
	
	static const uint8_t numpunc_lookup[32] = {
		0, 22, 38, '\0', '\0', '\0', '\0', 4, 		//  , !, ", #, $, %, &, ',
		54, 54, 20, '\0', 2, 36, 50, '\0',				// (, ), *, +, ,, -, ., /,
		26, 1, 3, 9, 25, 17, 11, 27, 							// 0, 1, 2, 3, 4, 5, 6, 7,
		19, 10, 18, 6, '\0', '\0', '\0', 38				// 8, 9, :, ;, <, =, >, ?,			
	};
	
	if(IS_LOWER(character)) {
		return lower_case_lookup[character-LOWER_CASE_OFFSET];
	}
	
	if(IS_CAPITAL(character)) {
		return upper_case_lookup[character-UPPER_CASE_OFFSET];
	}
	
	if(IS_NUMPUNC(character)) {
		return numpunc_lookup[character-NUMPUNC_OFFSET];
	}
	
	return '\0';
}

uint8_t braille_2_char(uint8_t braille, uint8_t modifier)
{	
	//lookup table for letters	
	static const uint8_t letter_lookup[64] =
	{
		'0', 'a', '0', 'b', '0', 'k', '0', 'l', // 00,01,02,03,04,05,06,07
		'0', 'c', 'i', 'f', '0', 'm', 's', 'p', // 08,09,10,11,12,13,14,15
		'0', 'e', '0', 'h', '0', 'o', '0', 'r', // 16,17,18,19,20,21,22,23
		'0', 'd', 'j', 'g', '0', 'n', 't', 'q', // 24,25,26,27,28,29,30,31
		'0', '0', '0', '0', '0', 'u', '0', 'v', // 32,33,34,35,36,37,38,39
		'0', '0', '0', '0', '0', 'x', '0', '0', // 40,41,42,43,44,45,46,47
		'0', '0', '0', '0', '0', 'z', '0', '0', // 48,49,50,51,52,53,54,55
		'0', '0', 'w', '0', '0', 'y', '0', '0'  // 56,57,58,59,60,61,62,63
	};

	//lookup table for letters	
	static const uint8_t capital_lookup[64] =
	{
		'0', 'A', '0', 'B', '0', 'K', '0', 'L', // 00,01,02,03,04,05,06,07
		'0', 'C', 'I', 'F', '0', 'M', 'S', 'P', // 08,09,10,11,12,13,14,15
		'0', 'E', '0', 'H', '0', 'O', '0', 'R', // 16,17,18,19,20,21,22,23
		'0', 'D', 'J', 'G', '0', 'N', 'T', 'Q', // 24,25,26,27,28,29,30,31
		'0', '0', '0', '0', '0', 'U', '0', 'V', // 32,33,34,35,36,37,38,39
		'0', '0', '0', '0', '0', 'X', '0', '0', // 40,41,42,43,44,45,46,47
		'0', '0', '0', '0', '0', 'Z', '0', '0', // 48,49,50,51,52,53,54,55
		'0', '0', 'W', '0', '0', 'Y', '0', '0'  // 56,57,58,59,60,61,62,63
	};

	//lookup table for numbers and punctuation
	static const uint8_t numpunc_lookup[64] =
	{
		'0', '1', ',', '2', '#', '0', ';', '0', // 00,01,02,03,04,05,06,07
		'0', '3', '9', '6', '0', '0', '0', '0', // 08,09,10,11,12,13,14,15
		'0', '5', ':', '8', '*', '0', '!', '0', // 16,17,18,19,20,21,22,23
		'0', '4', '0', '7', '0', '0', '0', '0', // 24,25,26,27,28,29,30,31
		'0', '0', '0', '0', '-', '0', '?', '0', // 32,33,34,35,36,37,38,39
		'0', '0', '0', '0', '0', '0', '0', '0', // 40,41,42,43,44,45,46,47
		'0', '0', '.', '0', '"', '0', '(', '0', // 48,49,50,51,52,53,54,55
		'0', '0', '0', '0', '0', '0', '0', '0'  // 56,57,58,59,60,61,62,63
	};

	if(modifier==LOWER_CASE_MOD){
		return letter_lookup[braille];
	}

	if(modifier==UPPER_CASE_MOD){
		return capital_lookup[braille];
	}

	if(modifier==NUMPUNC_MOD){
		return numpunc_lookup[braille];
	}

	return '\0';
}
