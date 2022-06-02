#include <stdio.h>
#include <time.h>
#include <inttypes.h>

uint32_t littleToBigEndian(uint32_t change){
	uint32_t B = 0;
	unsigned char tmp=0, l; // create two unsigned chars with size = 1 byte

	// create a for loop for converting big endian to little endian in 4 iteration 
    // because of difference in size between unsigned int and unsigned char is equal to 4/1 = 4
	for(l = 0; l < 4; l++) 
        {
        tmp = 0; // assign to tmp value of 0 
        tmp = change | tmp; // by using bitwise operator "OR" that copies a bit if it exists in either operand (disjunction)
        // for example A = 0011 1100
        //             B = 0000 1101
        //           A|B = 0011 1101
        B = tmp | (B << 8); // assign to big value of disjunction of "tmp" and "big", interpreted with 8 bit left shift,
        change = change >> 8; // make a right shift of bits in little  
    }
	return (B);
}