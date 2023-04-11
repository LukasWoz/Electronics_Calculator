#include "Logical_operations.h"



///////////////////////////////////////////////////////////////////////////////////
// This function checks if the selected option for logical operation exists.
///////////////////////////////////////////////////////////////////////////////////
//		
// INPUT:
//		Gates - a <map> with available logical operations
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
std::string check_selected_gates(std::map<int, std::string>& Gates) {
    bool stay{ false };
    int value;
    do {
        std::cout << "OPTION: ";
        std::cin >> value;
        if (Gates.find(value) == Gates.end()) {
            stay = true;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input; please re-enter.\n";
        }
        else
            stay = false;
    } while (stay == true);
    Clear();
    return Gates.at(value);
}




///////////////////////////////////////////////////////////////////////////////////////////
// This function takes the entered numbers by user and returns the length of the longer one
///////////////////////////////////////////////////////////////////////////////////////////
int length_check(char* num1, char* num2) {

    int size1 = strlen(num1);
    int size2 = strlen(num2);
    if (size1 > size2)
        return size1;

    else
        return size2;
}




/////////////////////////////////////////////////////////////////////////////////////
// This function performs the logical AND operation
/////////////////////////////////////////////////////////////////////////////////////
//		
// INPUT:
//		num1/num2 - user-entered binary sequences
//		
// OUTPUT:
//		Value of logical AND operation on user-entered data
//		
// REMARKS:
//		Uses the functions from Number_Systems to convert the entered binary values 
//      to a decimal. Logical operation is performed on decimal values.
//	
char* gAND(char* num1, char* num2) {

    return dec_to_any((any_to_dec(num1, 2) & any_to_dec(num2, 2)), 2);

}




/////////////////////////////////////////////////////////////////////////////////////
// This function performs the logical OR operation
/////////////////////////////////////////////////////////////////////////////////////
//		
// INPUT:
//		num1/num2 - user-entered binary sequences
//		
// OUTPUT:
//		Value of logical OR operation on user-entered data
//		
// REMARKS:
//		Uses the functions from Number_Systems to convert the entered binary values 
//      to a decimal. Logical operation is performed on decimal values.
//	
char* gOR(char* num1, char* num2) {

    return dec_to_any((any_to_dec(num1, 2) | any_to_dec(num2, 2)), 2);

}




/////////////////////////////////////////////////////////////////////////////////////
// This function performs the logical XOR operation
/////////////////////////////////////////////////////////////////////////////////////
//		
// INPUT:
//		num1/num2 - user-entered binary sequences
//		
// OUTPUT:
//		Value of logical XOR operation on user-entered data
//		
// REMARKS:
//		Uses the functions from Number_Systems to convert the entered binary values 
//      to a decimal. Logical operation is performed on decimal values.
//	
char* gXOR(char* num1, char* num2) {

    return dec_to_any((any_to_dec(num1, 2) ^ any_to_dec(num2, 2)), 2);

}





/////////////////////////////////////////////////////////////////////////////////////
// This function performs the logical NAND operation
/////////////////////////////////////////////////////////////////////////////////////
//		
// INPUT:
//		num1/num2 - user-entered binary sequences
//		
// OUTPUT:
//		output_str = Value of logical NAND operation on user-entered data
//		
// REMARKS:
//		Uses the functions from Number_Systems to convert the entered binary values 
//      to a decimal. Logical operation is performed on decimal values.
//      Uses function from AND operation.
//	
std::string gNAND(char* num1, char* num2) {
    // erasing leading zeros in the entered numbers
    num1 = dec_to_any(any_to_dec(num1, 2), 2);
    num2 = dec_to_any(any_to_dec(num2, 2), 2);

    std::string output_str(gAND(num1, num2));

    //zero-padding output value
    int zeros_numb = length_check(num1, num2) - output_str.length();
    output_str.insert(0, zeros_numb, '0');


    for (std::string::size_type i = 0; i < output_str.size(); i++) {
        if (output_str[i] == '0')
            output_str[i] = '1';
        else
            output_str[i] = '0';
    }

    return output_str;
}





/////////////////////////////////////////////////////////////////////////////////////
// This function performs the logical NOR operation
/////////////////////////////////////////////////////////////////////////////////////
//		
// INPUT:
//		num1/num2 - user-entered binary sequences
//		
// OUTPUT:
//		output_str = Value of logical NOR operation on user-entered data
//		
// REMARKS:
//		Uses the functions from Number_Systems to convert the entered binary values 
//      to a decimal. Logical operation is performed on decimal values.
//      Uses function from OR operation.
//
std::string gNOR(char* num1, char* num2) {

    // erasing leading zeros in the entered numbers
    num1 = dec_to_any(any_to_dec(num1, 2), 2);
    num2 = dec_to_any(any_to_dec(num2, 2), 2);

    std::string output_str(gOR(num1, num2));

    //zero-padding output value
    int zeros_numb = length_check(num1, num2) - output_str.length();
    output_str.insert(0, zeros_numb, '0');


    for (std::string::size_type i = 0; i < output_str.size(); i++) {
        if (output_str[i] == '0')
            output_str[i] = '1';
        else
            output_str[i] = '0';
    }

    return output_str;
}





/////////////////////////////////////////////////////////////////////////////////////
// This function performs the logical XNOR operation
/////////////////////////////////////////////////////////////////////////////////////
//		
// INPUT:
//		num1/num2 - user-entered binary sequences
//		
// OUTPUT:
//		output_str = Value of logical XNOR operation on user-entered data
//		
// REMARKS:
//		Uses the functions from Number_Systems to convert the entered binary values 
//      to a decimal. Logical operation is performed on decimal values.
//      Uses function from XOR operation.
//	
std::string gXNOR(char* num1, char* num2) {

    // erasing leading zeros in the entered numbers
    num1 = dec_to_any(any_to_dec(num1, 2), 2);
    num2 = dec_to_any(any_to_dec(num2, 2), 2);

    std::string output_str(gXOR(num1, num2));

    //zero-padding output value
    int zeros_numb = length_check(num1, num2) - output_str.length();
    output_str.insert(0, zeros_numb, '0');


    for (std::string::size_type i = 0; i < output_str.size(); i++) {
        if (output_str[i] == '0')
            output_str[i] = '1';
        else
            output_str[i] = '0';
    }

    return output_str;
}




/////////////////////////////////////////////////////////////
// This function displays the result of a logical operation.
/////////////////////////////////////////////////////////////
void logic_outp(char* num1, char* num2, std::string gate) {
    int width = length_check(num1, num2);
    std::cout << "\n\t";
    std::cout.width(width);
    std::cout.fill('0');
    std::cout << num1 << "\n\t";
    std::cout <<gate << "\n\t";
    std::cout.width(width);
    std::cout.fill('0');
    std::cout << num2 << "\n\t";
    std::cout.width(width);
    std::cout.fill('=');
    std::cout << "" << "\n\t";

    std::cout.width(width);
    std::cout.fill('0');
    if (gate == "AND")
        std::cout << gAND(num1, num2)<<std::endl;
    else if (gate == "NAND")
        std::cout << gNAND(num1, num2);
    else if (gate == "OR")
        std::cout << gOR(num1, num2);
    else if (gate == "NOR")
        std::cout << gNOR(num1, num2);
    else if (gate == "XOR")
        std::cout << gXOR(num1, num2);
    else if (gate == "XNOR")
        std::cout << gXNOR(num1, num2);
    else {
        std::cout << "Something went wrong. Exiting the program...\n";
        exit;
    }
    std::cout << "\n\n\n";
}