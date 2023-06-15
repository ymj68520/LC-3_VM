#pragma once
#include "types.h"
#include "registers.h"
#include "condition_flag.h"
#include "LoadingPrograms.h"
#include "memOpts.h"
#include <stdlib.h>
// let integer be its TC, just say it is sign extend
uint16_t sign_extend(uint16_t x, int bit_count);
// update flags as CPU compute result
void update_flags(uint16_t r);
// add operations
void ADD(uint16_t instr);
// LDI
void LDI(uint16_t instr);
// Bitwise AND
void AND(uint16_t instr);
// Bitwise NOT
void NOT(uint16_t instr);
// Branch
void BR (uint16_t instr);
// Jump
void JMP(uint16_t instr);
// Jump register
void JSR(uint16_t instr);
// Load
void LD (uint16_t instr);
// Load effective address
void LEA(uint16_t instr);
// Store
void ST (uint16_t instr);
// Store indirect
void STI(uint16_t instr);
// Store register
void STR(uint16_t instr);
// Bad Code
void BDC();

