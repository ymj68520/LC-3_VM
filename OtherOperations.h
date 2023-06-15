#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <Windows.h>
#include <conio.h>
#include "types.h"
HANDLE hStdin = INVALID_HANDLE_VALUE;
DWORD fdwMode, fdwOldMode;
// Load Arguments
void LoadArguments(int argc, char* argv[]);
// setup
void SetUp();
// handle interrupt
void handle_interrupt(int signal);
// disable input buffering
void disable_input_buffering();
// restore input buffering
void restore_input_buffering();

uint16_t check_key();