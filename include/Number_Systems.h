#pragma once

#ifndef Number_Systems_h
#define Number_Systems_h

#include <iostream>
#include <map>
#include "System_Record.h"


int check_selected(std::map<int, TSystem_Record>& Systems);
int char_to_int(char c);
char int_to_char(int i);
int any_to_dec(char* c, int n);
char* dec_to_any(int a, int n);
void Clear();
void pause();
void convert(int initial, int target, char* numb, std::string Sys1, std::string Sys2);

#endif




