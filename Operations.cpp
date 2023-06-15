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

void ADD(uint16_t instr) {
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

void LDI(uint16_t instr)
{
	uint16_t r0 = (instr >> 9) & 0x7; // destination register (DR)
	uint16_t pc_offset = sign_extend(instr & 0x1ff, 9); // PCoffset 9

	// add pc_offset to the current PC, look at that memory location to get the final address
	reg[r0] = mem_read(mem_read(reg[R_PC] + pc_offset));
	update_flags(r0);
}

void AND(uint16_t instr)
{
	uint16_t r0 = (instr >> 9) & 0x7;
	uint16_t r1 = (instr >> 6) & 0x7;
	uint16_t imm_flag = (instr >> 5) & 0x1;

	if (imm_flag) {
		uint16_t immSigned = sign_extend(instr & 0x1F, 5);
		reg[0] = reg[1] & immSigned;
	}
	else
	{
		uint16_t r2 = instr & 0x7;
		reg[r0] = reg[r1] & reg[r2];
	}
	update_flags(r0);
}

void NOT(uint16_t instr)
{
	uint16_t r0 = (instr >> 9) & 0x7;
	uint16_t r1 = (instr >> 6) & 0x7;

	reg[r0] = ~reg[r1];
	update_flags(r0);
}

void BR(uint16_t instr)
{
	uint16_t pc_offset = sign_extend(instr & 0x1FF, 9);
	uint16_t cond_flag = (instr >> 9) & 0x7;
	if (cond_flag & reg[R_COND]) {
		reg[R_PC] += pc_offset;
	}
}

void JMP(uint16_t instr)
{
	uint16_t r1 = (instr >> 6) & 0x7;
	reg[R_PC] = reg[r1];
}

void JSR(uint16_t instr)
{
	uint16_t long_flag = (instr >> 11) & 1;
	reg[R_R7] = reg[R_PC];
	if (long_flag) {
		uint16_t long_pc_offset = sign_extend(instr & 0x7FF, 11);
		reg[R_PC] += long_pc_offset;
	}
	else
	{
		uint16_t r1 = (instr >> 6) & 0x7;
		reg[R_PC] = reg[r1];	// JSRR
	}
}

void LD(uint16_t instr)
{
	uint16_t r0 = (instr >> 9) & 0x7;
	uint16_t r1 = (instr >> 6) & 0x7;
	uint16_t offset = sign_extend(instr & 0x3FF, 6);
	reg[r0] = mem_read(reg[r1] + offset);
	update_flags(r0);
}

void LEA(uint16_t instr)
{
	uint16_t r0 = (instr >> 9) & 0x7;
	uint16_t pc_offset = sign_extend(instr & 0x1FF, 9);
	reg[r0] = reg[R_PC] + pc_offset;
	update_flags(r0);
}

void ST(uint16_t instr)
{
	uint16_t r0 = (instr >> 9) & 0x7;
	uint16_t pc_offset = sign_extend(instr & 0x1FF, 9);
	mem_write(reg[R_PC] + pc_offset, reg[r0]);

}

void STI(uint16_t instr)
{
	uint16_t r0 = (instr >> 9) & 0x7;
	uint16_t pc_offset = sign_extend(instr & 0x1FF, 9);
	mem_write(mem_read(reg[R_PC] + pc_offset), reg[r0]);
}

void STR(uint16_t instr)
{
	uint16_t r0 = (instr >> 9) & 0x7;
	uint16_t r1 = (instr >> 6) & 0x7;
	uint16_t offset = sign_extend(instr & 0x3F, 6);
	mem_write(reg[r1] + offset, reg[r0]);
}

void BDC()
{
	abort();
}
