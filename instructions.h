#pragma once
enum IOPCODE
{
	OP_BR = 0,  // branch
	OP_ADD,		// add
	OP_LD,		// Load
	OP_ST,		// Store
	OP_JSR,		// Jump Register
	OP_AND,		// bitwise and
	OP_LDR,		// Load Register
	OP_STR,		// Store Register
	OP_RTI,		// unused
	OP_NOT,		// bitwise not
	OP_LDI,		// Load indirect
	OP_STI,		// Store indirect
	OP_JMP,		// JUMP
	OP_RES,		// reserved (unused)
	OP_LEA,		// Load effective address
	OP_TRAP		// execyte trap
};