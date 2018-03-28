#include "Name.h"

using ::std::experimental::optional;

model::Name::Name(const std::string &first_names_surname) {
    std::regex pattern ( "([a-zA-Z]+\\s+)(?:([a-zA-Z]+\\s+))?(?:([a-zA-Z]+\\s+))?([a-zA-Z-]+)" );
    std::smatch result;
    regex_search( first_names_surname, result, pattern );

    std::string first_name = result[1];
    first_name.erase(std::remove_if(first_name.begin(), first_name.end(), isspace), first_name.end());
    first_name_ = first_name;
    std::string second_name = result[2];
    second_name.erase(std::remove_if(second_name.begin(), second_name.end(), isspace), second_name.end());
    if ( second_name != "")
        second_name_ = second_name;
    std::string third_name = result[3];
    third_name.erase(std::remove_if(third_name.begin(), third_name.end(), isspace), third_name.end());
    if ( third_name != "" )
        third_name_ = third_name;
    std::string surname = result[4];
    surname.erase(std::remove_if(surname.begin(), surname.end(), isspace), surname.end());
    last_name_ = surname;
}


std::string model::Name::FirstName() const {
    return first_name_;
}

optional<std::string> model::Name::SecondName() const {
    return second_name_;
}

optional<std::string> model::Name::ThirdName() const {
    return third_name_;
}

std::string model::Name::Surname() const {
    return last_name_;
}

std::string model::Name::ToFullInitials() const {
    std::stringstream full_initials;
    full_initials << first_name_[0] << ". ";
    if ( second_name_ != "" )
        full_initials << second_name_[0] << ". ";
    if ( third_name_ != "" )
        full_initials << third_name_[0] << ". ";
    full_initials << last_name_[0] << ".";
    return full_initials.str();
}

std::string model::Name::ToFirstNamesInitials() const {
    std::stringstream first_name_initials;
    first_name_initials << first_name_[0] << ". ";
    if ( second_name_ != "" )
        first_name_initials << second_name_[0] << ". ";
    if ( third_name_ != "" )
        first_name_initials << third_name_[0] << ". ";
    first_name_initials << last_name_;
    return first_name_initials.str();
}

std::string model::Name::ToSurnameNames() const {
    std::string from_surname_to_name = this->last_name_;
    from_surname_to_name += " ";
    from_surname_to_name += this->first_name_;
    if ( this->second_name_ != "" ) {
        from_surname_to_name += " ";
        from_surname_to_name += this->second_name_;
    }

    if ( this->third_name_ != "" ) {
        from_surname_to_name += " ";
        from_surname_to_name += this->third_name_;
    }

    return from_surname_to_name;
}

std::string model::Name::ToNamesSurname() const {
    std::string from_name_to_surname = this->first_name_;
    if ( this->second_name_ != "" ) {
        from_name_to_surname += " ";
        from_name_to_surname += this->second_name_;
    }
    if ( this->third_name_ != "" ) {
        from_name_to_surname += " ";
        from_name_to_surname += this->third_name_;
    }
    from_name_to_surname += " ";
    from_name_to_surname += this->last_name_;
    return from_name_to_surname;
}

bool model::Name::IsBeforeBySurname( const Name &other ) const {
    std::string surname_to_compare = other.last_name_;
    std::transform(surname_to_compare.begin(), surname_to_compare.end(), surname_to_compare.begin(), ::tolower);
    std::string surname = this->last_name_;
    std::transform(surname.begin(), surname.end(), surname.begin(), ::tolower);
    if ( surname.compare(surname_to_compare) <= 0)
        return true;
    else
        return false;
}

bool model::Name::IsBeforeByFirstName(const Name &other) const {
    std::string name_to_comapre = other.first_name_;
    std::transform(name_to_comapre.begin(), name_to_comapre.end(), name_to_comapre.begin(), ::tolower);
    std::string first_name = this->first_name_;
    std::transform(first_name.begin(), first_name.end(), first_name.begin(), ::tolower);
    if ( first_name.compare(name_to_comapre) <= 0)
        return true;
    else
        return false;
}