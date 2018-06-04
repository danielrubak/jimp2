#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>
#include <functional>

namespace academia {
    class TeacherId {
    public:
        explicit TeacherId(int id_);
        operator int () const;
        bool operator != (const TeacherId & other) const;
        bool operator == (const TeacherId & other) const;
    private:
        int mId;
    };

    class Teacher {
    public:
        Teacher(const TeacherId &id, const std::string &name, const std::string &department);
        const TeacherId & Id() const;
        const std::string & Name() const;
        const std::string & Department() const;
        bool operator == (const Teacher& other) const;
        bool operator != (const Teacher& other) const;
    private:
        TeacherId mId;
        std::string mName;
        std::string mDepartment;
    };

    class TeacherHash {
    public:
        size_t operator() (const Teacher & toHash) const;
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H