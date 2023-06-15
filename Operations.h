#pragma once
#include "types.h"
#include "registers.h"
#include "condition_flag.h"
// let integer be its TC, just say it is sign extend
uint16_t sign_extend(uint16_t x, int bit_count);
// update flags as CPU compute result
void update_flags(uint16_t r);
// add operations
void ADD(uint16_t instr, int bit_count);
// C LDI Sample

