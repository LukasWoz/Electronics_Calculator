#include "display.h"


//////////////////////////////////////////////////////////////////////////
// This function displays available number systems
//////////////////////////////////////////////////////////////////////////
void disp_conv(std::map<int, TSystem_Record>& Systems) {
    std::map<int, TSystem_Record>::iterator it;
    std::cout << "\tOPTION\n";
    for (it =Systems.begin(); it != Systems.end(); ++it) {
        std::cout << "\t[" << it->first << "]\t" << it->second << '\n';
    }
    std::cout << std::endl;
}


//////////////////////////////////////////////////////////////////////////
// This function displays available logical operations
//////////////////////////////////////////////////////////////////////////
void disp_gates(std::map<int, std::string>& Gates) {
    std::map<int, std::string>::iterator it;
    std::cout << "\tOPTION\tOPERATION\n";
    for (it = Gates.begin(); it != Gates.end(); ++it) {
        std::cout << "\t[" << it->first << "]\t" << it->second << '\n';
    }
    std::cout << std::endl;
}




///////////////////////////////////////////////////////////////////////////////////
// This function displays the basic information in the program. 
// Responsible for calling the main functions of the calculator.
///////////////////////////////////////////////////////////////////////////////////
//		
// INPUT:
//		opt == options - displaying the calculator operations that can be selected
//      opt == systems - performing number conversion between number systems
//      opt == logical - performing logical operations
//		
int disp(std::string opt) {

    if (opt == "options") {
        Clear();
        std::cout << "Choose what operation you would like to perform:\n\n";
        std::cout << "\tConversion between number systems - press [c]\n";
        std::cout << "\tLogical operations                - press [o]\n";
        std::cout << "\n\tExit                              - press [ESC]\n";
    }

    else if (opt == "systems") {

        Clear();
        //Creating elements for class Convert
        TSystem_Record Decimal("Decimal", 10);
        TSystem_Record Binary("Binary", 2);
        TSystem_Record Octal("Octal", 8);
        TSystem_Record Hexadecimal("Hexadecimal", 16);
        TSystem_Record Go_back("EXIT", 0);

        std::map<int, TSystem_Record> Convert_Record;
       
        Convert_Record.insert(std::pair<int, TSystem_Record>(1, Decimal));
        Convert_Record.insert(std::pair<int, TSystem_Record>(2, Binary));
        Convert_Record.insert(std::pair<int, TSystem_Record>(3, Octal));
        Convert_Record.insert(std::pair<int, TSystem_Record>(4, Hexadecimal));
        Convert_Record.insert(std::pair<int, TSystem_Record>(9, Go_back));
       

        //variables for number convertion
        int initial;    //system index of the number entered by the user
        int target;     //index of the target number system
        char* number;

        std::cout << "Choose the system in which you want to enter number: ";
        std::cout << "[enter OPTION and press ENTER]  \n\n";
        disp_conv(Convert_Record);
        initial = check_selected(Convert_Record);

        if (initial == 9) 
            return 0;
       
        std::cout << "Choose the target system:  ";
        std::cout << "[enter OPTION and press ENTER]  \n\n";
        disp_conv(Convert_Record);
        target = check_selected(Convert_Record);

        if (target == 9)
            return 0;

        number = new char[50];
        do {
            std::cout << "Enter number to convert: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> number;
        } while (correct_numb(number, initial, target) == false);

        convert(Convert_Record.at(initial).Get_NumbBase(), Convert_Record.at(target).Get_NumbBase(),
            number, Convert_Record.at(initial).Get_NumbSystem(), Convert_Record.at(target).Get_NumbSystem());

        delete[] number;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        pause();
        return 0;

    }


    else if (opt == "logical") {

        Clear();
        std::map<int, std::string> GatesRecord;
        GatesRecord.insert(std::pair<int, std::string>(1, "AND"));
        GatesRecord.insert(std::pair<int, std::string>(2, "NAND"));
        GatesRecord.insert(std::pair<int, std::string>(3, "OR"));
        GatesRecord.insert(std::pair<int, std::string>(4, "NOR"));
        GatesRecord.insert(std::pair<int, std::string>(5, "XOR"));
        GatesRecord.insert(std::pair<int, std::string>(6, "XNOR"));
        GatesRecord.insert(std::pair<int, std::string>(9, "EXIT"));

        //variables for logical operations
        std::string gate_name;
        char* number1;
        char* number2;
        char* output;
        number1 = new char[50];
        number2 = new char[50];
        output = new char[50];


        std::cout << "Select the type of logical operation you want to perform: ";
        std::cout << "[enter OPTION and press ENTER]  \n\n";

        //Display of available options for logical operations
        disp_gates(GatesRecord);

        //Function that checks if there is such an option - 
        gate_name = check_selected_gates(GatesRecord);

        if (gate_name == "EXIT") {
            return 0;
        }

        std::cout << "Operation: " << gate_name << std::endl;

        do {
            std::cout << "Please enter first number: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> number1;
        } while (correct_numb(number1, 2, 0) == false);


        do {
            std::cout << "Please enter second number: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> number2;
        } while (correct_numb(number2, 2, 0) == false);


        logic_outp(number1, number2, gate_name);

        delete[] number1;
        delete[] number2;
        delete[] output;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        pause();
        return 0;

    }

}






///////////////////////////////////////////////////////////////////////////////////////////////////////
// This function checks if the entered data is correct
///////////////////////////////////////////////////////////////////////////////////////////////////////
//		
// OUTPUT:
//		check - true / false : information whether the number has been entered correctly
// 
//
bool correct_numb(char* input, int base1, int base2) {
    bool check = true;
    int i = std::strlen(input);




    //////////////////////////////////////////////////////////////////////////////////////////
    //verification of the entered number in decimal system
    //////////////////////////////////////////////////////////////////////////////////////////
    if (base1 == 1) {

        //verification of entered characters
        for (int i = std::strlen(input) - 1; i >= 0; i--) {
            if (input[i] < '0' || input[i] > '9') {
                check = false;
                std::cout << "Invalid characters entered.\n" << std::endl;
                return check;
            }
        }

        //checking if the entered number does not exceed the range for a given number system
        int input_int = atoi(input);
        if (input_int > 1073741823 || (base2 == 4 && input_int > 268435455)) {
            check = false;
            std::cout << "Number is too big.\n" << std::endl;
        }

    }


    

    //////////////////////////////////////////////////////////////////////////////////////////
    //verification of the entered number in binary system
    //////////////////////////////////////////////////////////////////////////////////////////
    if (base1 == 2) {

        //verification of entered characters
        for (int i = std::strlen(input) - 1; i >= 0; i--) {
            if (input[i] < '0' || input[i] > '1') {
                check = false;
                std::cout << "Invalid characters entered.\n" << std::endl;
                return check;
            }
        }

        //checking if the entered number does not exceed the range for a given number system
        if (i > 30 || (base2 == 4 && i > 28)) {
            check = false;
            std::cout << "Too big value.\n" << std::endl;
        }
    }

   


    //////////////////////////////////////////////////////////////////////////////////////////
    //verification of the entered number in octal system
    //////////////////////////////////////////////////////////////////////////////////////////
    if (base1 == 3) {

        //verification of entered characters
        for (int i = std::strlen(input) - 1; i >= 0; i--) {
            if (input[i] < '0' || input[i] > '7') {
                check = false;
                std::cout << "Invalid characters entered.\n" << std::endl;
                return check;
            }
        }

        //checking if the entered number does not exceed the range for a given number system
        int input_int = atoi(input);
        int i = std::strlen(input);
        if (i > 10 || (base2 == 4 && input_int > 1777777777)) {
            check = false;
            std::cout << "Number is too big.\n" << std::endl;
        }

    }



    //////////////////////////////////////////////////////////////////////////////////////////
    //verification of the entered number in hexadecimal system
    //////////////////////////////////////////////////////////////////////////////////////////
    if (base1 == 4) {

        for (int i = std::strlen(input) - 1; i >= 0; i--) {

            //verification of entered characters
            if (input[i] < '0' || (input[i] > '9' && input[i] < 'A') || input[i]>'F') {
                check = false;
                std::cout << "Invalid characters entered.\n" << std::endl;
                return check;
            }
        }

        //checking if the entered number does not exceed the range for a given number system
        int i = std::strlen(input);
        if (i > 7) {
            check = false;
            std::cout << "Number is too big.\n" << std::endl;
        }

    }

    return check;
}