// 8080func.h
#ifndef _8080FUNC_H
#define _8080FUNC_H

#include "8080emulator.c"  // Include the necessary structures (like State8080)

// Declare the function to disassemble or emulate instructions
void UnimplementedInstruction(State8080* state);
void Emulate8080p(State8080* state);

#endif