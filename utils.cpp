#include "utils.hpp"
#include <regex>
#include <stdexcept>

void check_email(const std::string& email) {
    std::regex pattern(R"(.+@.+\..+)");

    if (!std::regex_match(email, pattern)) {
        throw std::invalid_argument("Invalid email format");
    }
}
