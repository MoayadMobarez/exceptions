#include <iostream>
#include <string>
#include "utils.hpp"

int main() {
    std::string email;

    while (true) {
        std::cout << "Enter your email address: ";
        std::getline(std::cin, email);

        try {
            check_email(email);
            std::cout << "Valid email entered. Exiting program.\n";
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            std::cout << "Please try again.\n";
        }
    }

    return 0;
}
