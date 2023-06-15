/*
 * Thanks to Justin Meiners and Ryan Pendleton
 * https://www.jmeiners.com/
 * https://www.ryanp.me/
 * https://www.jmeiners.com/lc3-vm/#memory-mapped-registers-block-81
 */
#include "types.h"
#include "memory.h"
#include "registers.h"
#include "instructions.h"
#include "condition_flag.h"
#include "memOpts.h"
#include "OtherOperations.h"
#include "trapRoutine.h"

bool running = true;

int main(int argc, char* argv[]) {
//	{Load Argument, 12}
	LoadArguments(argc, argv);
//	{Setup, 12}

	// Set the PC to starting position
	enum STRSTES{ PC_START = 0x3000 };

//	bool running = true;
	while (running)
	{
		uint16_t instr = 0;
//		= mem_read(reg[R_PC]++);
		uint16_t op = instr >> 12;

		switch (op)
		{
		case OP_ADD:

			break;
		case OP_AND:

			break;
		case OP_NOT:

			break;
		case OP_BR:

			break;
		case OP_JMP:

			break;
		case OP_JSR:

			break;
		case OP_LD:

			break;
		case OP_LDI:

			break;
		case OP_LDR:

			break;
		case OP_ST:

			break;
		case OP_STI:

			break;
		case OP_STR:

			break;
		case OP_TRAP:

			break;
		case OP_RES:
		case OP_RTI:
		default:
			// Bad OPCode
			break;
		}
	}
	// shutdown,12

}