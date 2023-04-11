#include "Number_Systems.h"


/////////////////////////////////////////////////////////////////
// This function checks if the selected conversion option exists.
/////////////////////////////////////////////////////////////////
//		
// INPUT:
//		Systems - a <map> with available number systems
//		
// OUTPUT:
//		value - index of the selected option, if it has been selected correctly
//      
//      Information about the lack of a selected option if it was wrongly selected
//		
// REMARKS:
//		Loop in the function. 
//      The program is there until user selects the correct option
//	
int check_selected(std::map<int, TSystem_Record>& Systems) {
    bool stay{ false };
    int value;
    do {
        std::cout << "OPTION: ";
        std::cin >> value;
        if (Systems.find(value) == Systems.end()) {
            stay = true;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input; please re-enter.\n";
        }
        else
            stay = false;
    } while (stay == true);
    Clear();
    return value;
}


//converts char values to integer
int char_to_int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'F') {
        return 10 + c - 'A';
    }
    std::cout << "Invalid characters entered." << std::endl;
    return 0;
}

//converts integer values to char
char int_to_char(int i) {
    if (i >= 0 && i <= 9) {
        return '0' + i;
    }
    if (i >= 10 && i <= 15) {
        return 'A' + i - 10;
    }
    return ' ';
}

//converts any number to decimal 
int any_to_dec(char* c, int d) {
    int numb{ 0 };
    for (int i = std::strlen(c) - 1, pow = 1; i >= 0; i--) {
        numb += char_to_int(c[i]) * pow;
        pow *= d;
    }
    return numb;
}


//converts decimal number to any 
char* dec_to_any(int d, int c) {
    int len{ 0 };
    int pow{ 1 };
    while (d > pow) {
        pow *= c;
        len++;
    }
    if (d == pow) {
        len++;
    }
    char* output = new char[len + 1];
    for (int i = len, pow = 1; i >= 0; i--) {
        output[i - 1] = int_to_char(d % c);
        d /= c;
    }
    output[len] = '\0';
    return output;
}


/////////////////////////////////////////////////////////////////////////
// This function clears the console
/////////////////////////////////////////////////////////////////////////
void Clear(){
#if defined _WIN32
    system("cls");

#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");

#elif defined (__APPLE__)
    system("clear");
#endif
}


///////////////////////////////////////////////////////////////////////
// This function pauses the program
///////////////////////////////////////////////////////////////////////
void pause() {
    std::cin.clear();
    std::cout << std::endl << "Press ENTER to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
// This function displays the result of converting a number to the new number system
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void convert(int initial, int target, char* numb, std::string Sys1, std::string Sys2) {
    std::cout << Sys1 << " number: " << numb << std::endl;
    std::cout << "\n" << Sys2 << " number: " << dec_to_any(any_to_dec(numb, initial), target) << "\n\n\n";
}
