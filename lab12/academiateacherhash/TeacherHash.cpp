#include "TeacherHash.h"

using namespace academia;

TeacherId::TeacherId(int id) : mId(id) {}

TeacherId::operator int() const {
    return mId;
}

bool TeacherId::operator != (const TeacherId &other) const {
    if ( mId != other.mId ) {
        return true;
    }
    return false;
}

bool TeacherId::operator == (const TeacherId &other) const {
    if ( mId == other.mId ) {
        return true;
    }
    return false;
}

Teacher::Teacher(const TeacherId &id, const std::string &name,
                           const std::string &department) : mId(id), mName(name), mDepartment(department) {}

const TeacherId & Teacher::Id() const {
    return mId;
}

const std::string & Teacher::Name() const {
    return mName;
}

const std::string & Teacher::Department() const {
    return mDepartment;
}

bool Teacher::operator == (const Teacher &other) const {
    if ( mId == other.mId and mName == other.mName and mDepartment == other.mDepartment ) {
        return true;
    }
    return false;
}

bool Teacher::operator != (const Teacher &other) const {
    if ( mId != other.mId or mName != other.mName or mDepartment != other.mDepartment ) {
        return true;
    }
    return false;
}

size_t TeacherHash::operator()(const Teacher & to_hash) const{
    size_t hash = std::hash<int>()((int)to_hash.Id());
    hash += hash<<2+std::hash<std::string>()(to_hash.Name());
    hash += hash<<2+std::hash<std::string>()(to_hash.Department());
    return hash;
}