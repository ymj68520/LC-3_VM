#include "trapRoutine.h"

void trap_getc()
{
	reg[R_R0] = (uint16_t)getchar();
	update_flags(R_R0);
}

void trap_output()
{
	putc((char)reg[R_R0], stdout);
	fflush(stdout);
}

void trap_in()
{
	printf("Enter a character: ");
	char c = getchar();
	putc(c, stdout);
	fflush(stdout);
	reg[R_R0] = (uint16_t)c;
	update_flags(R_R0);
}
/*
 * one char per byte (two bytes per word)
 * here we need to swap back to
 * big endian format
 */
void trap_putsp()
{
	uint16_t* c = memory + reg[R_R0];
	while (*c) {
		char char1 = (*c) & 0xFF;
		putc(char1, stdout);
		char char2 = (*c) >> 8;
		if (char2)	putc(char2, stdout);
		++c;
	}
	fflush(stdout);
}

void trap_halt()
{
	puts("HALT");
	fflush(stdout);
	running = 0;
}

