#pragma once
#include <stdio.h>
#include <stdint.h>

/*
 The first 16 bits of the program file specify the address in memory 
 where the program should start. This address is called the origin. 
 It must be read first, after which the rest of the data can be read 
 from the file into memory starting at the origin address.
*/
void read_image_file(FILE* file);
/*
Notice that swap16 is called on each loaded value.
LC-3 programs are big-endian, but most modern computers are little-endian.
So, we need to swap each uint16 that is loaded.
(If you happen to be using an obscure computer, like an old PPC Mac, then do not swap.)
*/
uint16_t swap16(uint16_t x);
// read image file
int read_image(const char* image_path);