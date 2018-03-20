#ifndef JIMP2_MODELNAMES_H
#define JIMP2_MODELNAMES_H

#include <iostream>
#include <string>
#include <regex>
#include <sstream>

class Name {
public:
    Name();
    Name(std::string full_name_path);
    ~Name();
    std::string FirstName();
    std::string SecondName();
    std::string ThirdName();
    std::string Surname();
    std::string ToFullInitials();
    std::string ToFirstNamesInitials();
    std::string ToSurnameNames();
    std::string ToNamesSurname();
    bool IsBeforeBySurname(std::string surname_to_compare);
    bool IsBeforeByFirstName(std::string name_to_comapre);

private:
    std::string first_name;
    std::string second_name;
    std::string third_name;
    std::string surname;
};

#endif //JIMP2_MODELNAMES_H
