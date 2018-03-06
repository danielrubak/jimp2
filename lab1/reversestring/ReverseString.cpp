#include "ReverseString.h"

std::string reverse(std::string str) {
    if (str.length() >= 0 && str.length() < 2) {
        return str;
    } else {
        return reverse(str.substr(1, str.length())) + str.at(0);
    }
}
