#include <iostream>
#include <stdexcept>
#include "Rational.h"
#include "Pair.h"

//try виняток-помилка
int main() {
    try {
        
        Rational r1(19, 20);
        Rational r2(2, 6);

        
        Rational sum = r1 + r2;
        Rational difference = r1 - r2;
        Rational division = r1 / r2;

        
        std::cout << "Sum: " << sum << std::endl;
        std::cout << "Difference: " << difference << std::endl;
        std::cout << "Division: " << division << std::endl;

       
        std::string r1_str = static_cast<std::string>(r1);
        std::cout << "r1 as string: " << r1_str << std::endl;

        //модифікація
        std::cout << "Before modification: " << r1 << std::endl;
        r1.setFirst(3);
        r1.setSecond(8);
        std::cout << "After modification: " << r1 << std::endl;

        
        Rational r3(0, 0); // неприпустимий
        std::cout << "Enter a rational number (format: a/b): ";
        std::cin >> r3;
        std::cout << "Entered rational number: " << r3 << std::endl;

        
        std::cout << "r3 after modification: " << r3 << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
