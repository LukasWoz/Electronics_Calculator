// Calculator_for_electronics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "display.h"
#include <conio.h>   //_getch()


int main()
{
    unsigned char action;
    unsigned char act;
    bool stay{ true };
    bool val{ true };
    
    std::cout << "\t*** ELECTRONICS_CALCULATOR ***\n\n";
   
    pause();
    
    while (stay==true) {
        
        disp("options");
        action = _getch();

        switch (action) {
            
        case 99:    //Conversion between number systems
            disp("systems");
            break;

        case 111:  //Logical operations
            disp("logical");
            break;

        case 27:
            stay = false;
            break;
        }

    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
