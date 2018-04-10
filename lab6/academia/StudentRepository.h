#ifndef JIMP2_STUDENTREPOSITORY_H
#define JIMP2_STUDENTREPOSITORY_H

#include <string>
#include <iostream>

namespace academia {
    class StudentRepository {
    public:

    private:

    };

    class StudyYear {
    public:
        StudyYear &operator++();
        StudyYear &operator--();
        std::istream& operator>>(std::istream &is, StudyYear& y);
        std::ostream& operator<< (std::ostream& stream, const StudyYear& y);
    private:
        int year_;
    };

    class Student {
    public:

    private:
        std::string id_;
        std::string first_name_;
        std::string last_name_;
        std::string program_;
        StudyYear year_;
    };


}


#endif //JIMP2_STUDENTREPOSITORY_H
