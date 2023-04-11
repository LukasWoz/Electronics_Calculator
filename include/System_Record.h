#pragma once

#ifndef System_Record_h
#define System_Record_h

#include <iostream>


///////////////////////////////////////////////////////////
// This class implements numeric systems
///////////////////////////////////////////////////////////
class TSystem_Record {
	std::string NumbSystem;   //Name of the number system
	int NumbBase;        //Base of the number system.

public:

	//Constructor
	TSystem_Record(std::string NS = "NONE", int NB = 0)
		:NumbSystem(NS), NumbBase(NB) {}

	//Functions to read data
	std::string Get_NumbSystem(void)const { return NumbSystem; }
	int Get_NumbBase(void)const { return NumbBase; }

	//Functions to set data
	void Set_NumbSystem(const std::string s) { NumbSystem = s; }
	void Set_NumbBase(int b) { NumbBase = b; }
	

};

std::ostream& operator << (std::ostream& o, const TSystem_Record& obj);
std::istream& operator >> (std::istream& i, TSystem_Record& obj);

#endif