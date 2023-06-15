#pragma once
#include "memory.h"
#include "registers.h"
#include "Operations.h"
#include <stdio.h>
// Input Character
void trap_getc();
// Output Character
void trap_output();
// Prompt for Input Character
void trap_in();
// Output String
void trap_putsp();
// Halt Program
extern bool running;
void trap_halt();