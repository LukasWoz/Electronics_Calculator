#pragma once

#ifndef display_h
#define display_h

#include <iostream>
#include <map>
#include "Number_Systems.h"
#include "Logical_operations.h"

void disp_conv(std::map<int, TSystem_Record>& Systems);
void disp_gates(std::map<int, std::string>& Gates);
bool correct_numb(char* input, int base1, int base2);
int disp(std::string opt);

#endif