#include "DoubleBasePalindromes.h"

std::string Decimal2Binary(int dec)
{
    std::string bin;
    while( dec!=0 ) {
        bin = ( dec%2 == 0 ? "0" : "1" ) + bin;
        dec /= 2;
    }
    return bin;
}

bool IsPalindrome(std::string str) {
    if (str == std::string(str.rbegin(), str.rend()))
        return true;
    else
        return false;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    uint64_t counter = 0;
    for ( int i = 1; i < max_vaule_exculsive; i++ ) {
        std::string decValue = std::to_string(i);
        if( IsPalindrome(decValue) && IsPalindrome(Decimal2Binary(i)) )
            counter += i;
    }
    return counter;
}