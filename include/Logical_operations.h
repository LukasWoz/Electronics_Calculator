#pragma once

#ifndef Logical_operations_h
#define Logical_operations_h

#include "Number_Systems.h"

std::string check_selected_gates(std::map<int, std::string>& Gates);
int length_check(char* num1, char* num2);
char* gAND(char* num1, char* num2);
char* gOR(char* num1, char* num2);
char* gXOR(char* num1, char* num2);
std::string gNAND(char* num1, char* num2);
std::string gNOR(char* num1, char* num2);
std::string gXNOR(char* num1, char* num2);
void logic_outp(char* num1, char* num2, std::string gate);

#endif