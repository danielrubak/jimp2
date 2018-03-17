#include "Square.h"
#include "../point/Point.cpp"

Square::Square(): first_coordinate (0,0), second_coordinate(0,0), third_coordinate(0,0), fourth_coordinate(0,0) {
}

Square::Square(Point point_1, Point point_2, Point point_3, Point point_4) {
    first_coordinate = point_1;
    second_coordinate = point_2;
    third_coordinate = point_3;
    fourth_coordinate = point_4;
}

Square::~Square() {
    //std::cout << "Destructor of the point: (" << this->GetX() << "; " << this->GetY() << ")" << std::endl;
}

double Square::Circumference() {
    double first_side = (this->first_coordinate).Distance(this->second_coordinate);
    double second_side = (this->first_coordinate).Distance(this->second_coordinate);
    double third_side = (this->first_coordinate).Distance(this->second_coordinate);
    double fourth_side = (this->first_coordinate).Distance(this->second_coordinate);
    return (first_side + second_side + third_side + fourth_side);
}

double Square::Area() {
    double side = (this->first_coordinate).Distance(this->second_coordinate);
    return std::pow(side, 2);
}