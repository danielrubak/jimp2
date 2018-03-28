#include "Name.h"

int main() {
    model::Name first_person ("Just\t\t\n\r \tSurname");
    std::string first_name, surname, full_initials, first_name_initials, from_surname_to_name, from_name_to_surname, surname_to_compare, first_name_to_compare;
    std::experimental::optional<std::string> second_name;
    std::experimental::optional<std::string> third_name;
    first_name = first_person.FirstName();
    std::cout << "First name: '" << first_name << "'" << std::endl;
    second_name = first_person.SecondName();
    if ( second_name.value() != "" )
        std::cout << "Second name: '" << second_name.value() << "'" << std::endl;
    third_name = first_person.ThirdName();
    if ( third_name.value() != "" )
        std::cout << "Third name: '" << third_name.value() << "'" << std::endl;
    surname = first_person.Surname();
    std::cout << "Surname: '" << surname << "'" << std::endl;
    full_initials = first_person.ToFullInitials();
    std::cout << "Full initials: " << full_initials << std::endl;
    first_name_initials = first_person.ToFirstNamesInitials();
    std::cout << "First names initials: " << first_name_initials << std::endl;
    from_surname_to_name = first_person.ToSurnameNames();
    std::cout << "From surname to names: " << from_surname_to_name << std::endl;
    from_name_to_surname = first_person.ToNamesSurname();
    std::cout << "From names to surname: " << from_name_to_surname << std::endl;
    return 0;
}