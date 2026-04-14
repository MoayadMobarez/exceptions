#include <iostream>
#include <string>
#include <map>
#include "utils.hpp"

int main() {
    std::map<std::string, std::string> accounts;
    bool logged_in = false;
    std::string current_user;
    int choice;

    while (true) {
        std::cout << "\n=== Menu ===\n";

        if (!logged_in) {
            std::cout << "1. Sign up\n";
            std::cout << "2. Login\n";
            std::cout << "0. Exit\n";
        } else {
            std::cout << "3. Logout\n";
            std::cout << "0. Exit\n";
        }

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (!logged_in) {
            if (choice == 1) {
                std::string email;
                std::string password;

                std::cout << "Enter email: ";
                std::getline(std::cin, email);

                try {
                    check_email(email);
                } catch (const std::invalid_argument& e) {
                    std::cout << e.what() << "\n";
                    continue;
                }

                if (accounts.find(email) != accounts.end()) {
                    std::cout << "Email already exists.\n";
                    continue;
                }

                std::cout << "Enter password: ";
                std::getline(std::cin, password);

                accounts.insert({email, password});
                std::cout << "Sign up successful.\n";
            }
            else if (choice == 2) {
                std::string email;
                std::string password;

                std::cout << "Enter email: ";
                std::getline(std::cin, email);

                std::cout << "Enter password: ";
                std::getline(std::cin, password);

                auto it = accounts.find(email);

                if (it != accounts.end() && it->second == password) {
                    logged_in = true;
                    current_user = email;
                    std::cout << "Login successful.\n";
                } else {
                    std::cout << "Invalid email or password.\n";
                }
            }
            else if (choice == 0) {
                std::cout << "Exiting program.\n";
                break;
            }
            else {
                std::cout << "Invalid choice.\n";
            }
        } else {
            if (choice == 3) {
                logged_in = false;
                current_user.clear();
                std::cout << "Logout successful.\n";
            }
            else if (choice == 0) {
                std::cout << "Exiting program.\n";
                break;
            }
            else {
                std::cout << "Invalid choice.\n";
            }
        }
    }

    return 0;
}
