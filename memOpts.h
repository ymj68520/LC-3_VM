#pragma once
#include "types.h"
// Memory Mapped Registers
enum MeMapReg
{
	MR_KBSR = 0xFE00,
	MR_KBDR = 0xFE02,
};
// Memory Access
void mem_write(uint16_t address, uint16_t val);
uint16_t mem_read(uint16_t address);