#include "ModelNames.h"

Name::Name() {
}

Name::Name(std::string full_name_path) {
    std::regex pattern ( "([a-zA-z]+\\s+)(?:([a-zA-z]+\\s+))?(?:([a-zA-z]+\\s+))?([a-zA-z]+)" );
    std::smatch result;
    regex_search( full_name_path, result, pattern );

    std::string first_name = result[1];
    first_name.erase(std::remove_if(first_name.begin(), first_name.end(), isspace), first_name.end());
    this->first_name = first_name;
    std::string second_name = result[2];
    second_name.erase(std::remove_if(second_name.begin(), second_name.end(), isspace), second_name.end());
    this->second_name = second_name;
    std::string third_name = result[3];
    third_name.erase(std::remove_if(third_name.begin(), third_name.end(), isspace), third_name.end());
    this->third_name = third_name;
    std::string surname = result[4];
    surname.erase(std::remove_if(surname.begin(), surname.end(), isspace), surname.end());
    this->surname = surname;
}

Name::~Name() {

}

std::string Name::FirstName() {
    return this->first_name;
}

std::string Name::SecondName() {
    return this->second_name;
}

std::string Name::ThirdName() {
    return this->third_name;
}

std::string Name::Surname() {
    return this->surname;
}

std::string Name::ToFullInitials() {
    std::stringstream full_initials;
    full_initials << this->first_name[0] << ". " << this->second_name[0] << ". " << this->third_name[0] << ". " << this->surname[0] << ".";
    return full_initials.str();
}

std::string Name::ToFirstNamesInitials() {
    std::stringstream first_name_initials;
    first_name_initials << this->first_name[0] << ". " << this->second_name[0] << ". " << this->third_name[0] << ". " << this->surname;
    return first_name_initials.str();
}

std::string Name::ToSurnameNames() {
    std::string from_surname_to_name = this->surname;
    from_surname_to_name += " ";
    from_surname_to_name += this->first_name;
    if ( this->second_name != "" ) {
        from_surname_to_name += " ";
        from_surname_to_name += this->second_name;
    }
    if ( this->third_name != "" ) {
        from_surname_to_name += " ";
        from_surname_to_name += this->third_name;
    }
    return from_surname_to_name;
}

std::string Name::ToNamesSurname() {
    std::string from_name_to_surname = this->first_name;
    if ( this->second_name != "" ) {
        from_name_to_surname += " ";
        from_name_to_surname += this->second_name;
    }
    if ( this->third_name != "" ) {
        from_name_to_surname += " ";
        from_name_to_surname += this->third_name;
    }
    from_name_to_surname += " ";
    from_name_to_surname = this->surname;
    return from_name_to_surname;
}

bool Name::IsBeforeBySurname(std::string surname_to_compare) {
    std::transform(surname_to_compare.begin(), surname_to_compare.end(), surname_to_compare.begin(), ::tolower);
    std::string surname = this->surname;
    std::transform(surname.begin(), surname.end(), surname.begin(), ::tolower);
    if ( surname.compare(surname_to_compare) <= 0)
        return true;
    else
        return false;
}

bool Name::IsBeforeByFirstName(std::string name_to_comapre) {
    std::transform(name_to_comapre.begin(), name_to_comapre.end(), name_to_comapre.begin(), ::tolower);
    std::string first_name = this->first_name;
    std::transform(first_name.begin(), first_name.end(), first_name.begin(), ::tolower);
    if ( first_name.compare(name_to_comapre) <= 0)
        return true;
    else
        return false;
}