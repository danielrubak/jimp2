#include "Serialization.h"
using namespace academia;

// ############################
// ##### Serializer class #####
// ############################

Serializer::Serializer(std::ostream *out) {
    pSerializerOut = out;
}

// ######################
// ##### Room class #####
// ######################

void Room::Serialize(Serializer *serializer) {
    serializer -> Header("room");
    serializer -> IntegerField("id", mId);
    serializer -> StringField("name", mRoomName);
    serializer -> StringField("type", roomTypeToString(mRoomType));
    serializer -> Footer("room");
}

void Room::Serialize(Serializer *serializer) const {
    serializer -> Header("room");
    serializer -> IntegerField("id", mId);
    serializer -> StringField("name", mRoomName);
    serializer -> StringField("type", this->roomTypeToString(mRoomType));
    serializer -> Footer("room");
}

Room::Room(int id, const std::string roomName, Type type) : mId(id), mRoomName(roomName), mRoomType(type) {}

std::string Room::roomTypeToString(Room::Type type) const {
    switch (type){
        case Type::COMPUTER_LAB:
            return "COMPUTER_LAB";
        case Type::LECTURE_HALL:
            return "LECTURE_HALL";
        case Type::CLASSROOM:
            return "CLASSROOM";
    }
}

// ##########################
// ##### Building class #####
// ##########################

Building::Building(int id, const std::string buildingName, const std::vector<std::reference_wrapper<const Serializable>> &rRooms) :
        mId(id), mBuildingName(buildingName), mRoomsVector(rRooms) {}

void Building::Serialize(Serializer *serializer) {
    serializer->Header("building");
    serializer->IntegerField("id", mId);
    serializer->StringField("name", mBuildingName);
    serializer->ArrayField("rooms", mRoomsVector);
    serializer->Footer("building");
}

void Building::Serialize(Serializer *serializer) const {
    serializer->Header("building");
    serializer->IntegerField("id", mId);
    serializer->StringField("name", mBuildingName);
    serializer->ArrayField("rooms", mRoomsVector);
    serializer->Footer("building");
}

// ################################
// ##### JsonSerializer class #####
// ################################

JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out) {}

void JsonSerializer::IsStreamEmpty() {
    if ( mStreamIsEmpty )
        mStreamIsEmpty = false;
    else
        *pSerializerOut << ", ";
}

void JsonSerializer::IntegerField(const std::string &field_name, int value) {
    this->IsStreamEmpty();
    *pSerializerOut << "\"" << field_name << "\": " << value;
}

void JsonSerializer::DoubleField(const std::string &field_name, double value) {
    this->IsStreamEmpty();
    *pSerializerOut << "\"" << field_name << "\": " << value;
}

void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    this->IsStreamEmpty();
    *pSerializerOut << "\"" << field_name << "\": \"" << value << "\"";
}

void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
    this->IsStreamEmpty();
    std::string stringValue = value ? "true" : "false";
    *pSerializerOut << "\"" << field_name << "\": \"" << stringValue << "\"";
}

void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
    value.Serialize(this);
}

void JsonSerializer::ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const Serializable>> &value) {
    this->IsStreamEmpty();
    *pSerializerOut << "\"" << field_name << "\": [";
    if ( !(value.empty()) ){
        for ( int i = 0; i < value.size(); i++ ) {
            mStreamIsEmpty = true;
            SerializableField(field_name, value[i].get());
            std::string separator = ( i+1 != value.size() ) ? ", " : "";
            *pSerializerOut << separator;
        }
    }
    *pSerializerOut << "]";
}

void JsonSerializer::Header(const std::string &object_name) {
    *pSerializerOut << "{";
}

void JsonSerializer::Footer(const std::string &object_name) {
    *pSerializerOut << "}";
}

// ###############################
// ##### XmlSerializer class #####
// ###############################

XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {}

void XmlSerializer::IntegerField(const std::string &field_name, int value) {
    *pSerializerOut << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void XmlSerializer::DoubleField(const std::string &field_name, double value) {
    *pSerializerOut << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
    *pSerializerOut << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
    std::string stringValue = value ? "true" : "false";
    *pSerializerOut << "\"" << field_name << "\": \"" << stringValue << "\"";
}

void XmlSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
    value.Serialize(this);
}

void XmlSerializer::ArrayField(const std::string &field_name,
                const std::vector<std::reference_wrapper<const Serializable>> &value) {
    *pSerializerOut << "<" << field_name << ">";
    for ( auto i : value ) {
        SerializableField(field_name, i);
    }
    *pSerializerOut << "<\\" << field_name << ">";
}

void XmlSerializer::Header(const std::string &object_name) {
    *pSerializerOut << "<" << object_name << ">";
}

void XmlSerializer::Footer(const std::string &object_name) {
    *pSerializerOut << "<\\" << object_name << ">";
}