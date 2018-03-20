#include "ModelNames.h"

int main() {
    Name first_person ("Thomas Jorge Jelly Cucumber");
    std::string first_name, second_name, third_name, surname, full_initials, first_name_initials, from_surname_to_name, from_name_to_surname, surname_to_compare, first_name_to_compare;
    first_name = first_person.FirstName();
    std::cout << "First name: '" << first_name << "'" << std::endl;
    second_name = first_person.SecondName();
    std::cout << "Second name: '" << second_name << "'" << std::endl;
    third_name = first_person.ThirdName();
    std::cout << "Third name: '" << third_name << "'" << std::endl;
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
    surname_to_compare = "Potato";
    if ( first_person.IsBeforeBySurname( surname_to_compare ) )
        std::cout << "Surname '" << first_person.Surname() << "' is before '" << surname_to_compare << "'" << std::endl;
    else
        std::cout << "Surname '" << first_person.Surname() << "' is after '" << surname_to_compare << "'" << std::endl;
    first_name_to_compare = "Albus";
    if ( first_person.IsBeforeByFirstName( first_name_to_compare ) )
        std::cout << "First name '" << first_person.FirstName() << "' is before '" << first_name_to_compare << "'" << std::endl;
    else
        std::cout << "First name '" << first_person.FirstName() << "' is after '" << first_name_to_compare << "'" << std::endl;
    return 0;
}