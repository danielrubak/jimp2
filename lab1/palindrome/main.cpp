#include <iostream>
#include <limits>
#include "Palindrome.h"

int main() {
    bool run = true;
    while ( run ) {
        int choice = 0;
        std::cout << "Choose one of the options: " << std::endl;
        std::cout << "1 - Enter word" << std::endl;
        std::cout << "2 - Exit" << std::endl;
        while ( !(std::cin >> choice) ) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again!" << std::endl;
            std::cout << "1 - Enter word" << std::endl;
            std::cout << "2 - Exit" << std::endl;
            std::cout << "Your choice: ";
        }
        if (choice == 1) {
            std::cout << "Enter word: " << std::endl;
            std::string word;
            std::cin >> word;
            bool answer = is_palindrome(word);
            if ( answer == true ) {
                std::cout << "Word \"" << word << "\" is a palindrom!" << std::endl;
            } else {
                std::cout << "Word \"" << word << "\" is not a palindrom!" << std::endl;
            }
        } else if ( choice == 2) {
            run = false;
        }
    }
    return 0;
}