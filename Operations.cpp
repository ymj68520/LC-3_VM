#include "Operations.h"
uint16_t sign_extend(uint16_t x, int bit_count) {
	if ((x >> (bit_count - 1)) & 1) {
		x |= (0xFFFF << bit_count);
	}
	return x;
}
void update_flags(uint16_t r) {
	if (reg[r] == 0) {
		reg[R_COND] = FL_ZRO;
	}
	else if (reg[r] >> 15) // 1 is the left-most bit indicates negative
	{
		reg[R_COND] = FL_NEG;
	}
	else
	{
		reg[R_COND] = FL_POS;
	}
}
void ADD(uint16_t instr, int bit_count) {
	uint16_t r0 = (instr >> 9) & 0x7; // rd
	uint16_t r1 = (instr >> 6) & 0x7; // rs
	uint16_t imm_flag = (instr >> 5) & 0x1; // it is a flag as you can see

	if (imm_flag) {
		uint16_t immSigned = sign_extend(instr & 0x1F, 5);
		reg[r0] = reg[r1] + immSigned;
	}
	else
	{
		uint16_t r2 = instr & 0x7;
		reg[r0] = reg[r1] + reg[r2];
	}
	update_flags(r0);
}
