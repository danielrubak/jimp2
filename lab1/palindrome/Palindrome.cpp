#include <iostream>
#include "Palindrome.h"

bool is_palindrome(std::string str) {
    if (str == std::string(str.rbegin(), str.rend())) {
        return true;
    } else {
        return false;
    }
}