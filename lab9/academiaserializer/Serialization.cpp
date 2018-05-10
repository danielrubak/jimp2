#include "Serialization.h"

using namespace academia;

Serializer::Serializer(std::ostream *out) {
    serializer_out = out;
}

void Room::Serialize(Serializer *serializer) {
    serializer -> Header("Room");
    serializer -> IntegerField("Id", id);
    serializer -> StringField("Name", room_name);
    serializer -> StringField("Type", roomTypeToString(room_type));
    serializer -> Footer("Room");
}

Room::Room(int id, std::string room_name, Type type) : id(id), room_name(room_name), room_type(type) {}

std::string Room::roomTypeToString(Room::Type type) {
    switch (type){
        case Type(0):
            return "Computer Lab";
        case Type(1):
            return "Lecture hall";
        case Type(2):
            return "Classroom";
    }
}