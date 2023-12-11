#include <iostream>
#include <string>




double map(char input) { // wish I could use actual mapping for this, but arduino doesn't have it
    if (input == '1') return 1;
    if (input == '2') return 2;
    if (input == '3') return 3;
    if (input == '4') return 4;
    if (input == '5') return 5;
    if (input == '6') return 6;
    if (input == '7') return 7;
    if (input == '8') return 8;
    if (input == '9') return 9;
    if (input == '0') return 0;
    return -1;
}

double pow(double base, double power) {

    // if (power == 1) return base;

    double output = base;

    for (int i = 0; i < power-1; i++) output *= base;

    return output;
}




double stringToDouble(std::string input) {
    double output = 0;
    
    bool negative = false;
    bool decimal = false;
    int decimalIndex = 0;
    for (char i : input) {

        double num = map(i);

        std::cout << "char: " << i << std::endl;

        std::cout << "num: " << num << std::endl;

        if (decimal) decimalIndex++;

        if (i == '-') {negative = true; continue;}
        if (i == '.') {decimal = true; continue;}


        else if (num == 0) {
            if (!decimal) output *= 10;
        }        

        else {

            if (decimal) output += num / (pow(10, decimalIndex));

            else output = output * 10 + num;
        }

        std::cout << "number: " << output << std::endl << std::endl;
        
    }

    if (negative) output *= -1;

    return output;
}





int main() {

    std::string input = "-55868553.332";

    double output = stringToDouble(input);

    std::cout << "input: \"" << input << "\"" << std::endl;
    std::cout << "output: " << output << std::endl;

    
}
