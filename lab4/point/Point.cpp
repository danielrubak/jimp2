#include "Point.h"

Point::Point(): x_(0),y_(0) {
    //std::cout << "Non-parametric constructor" << std::endl;
}

Point::Point(double x, double y) {
    //std::cout << "Parametric constructor" << std::endl;
    x_ = x;
    y_ = y;
}

Point::~Point() {
    //std::cout << "Destructor of the point: (" << this->GetX() << "; " << this->GetY() << ")" << std::endl;
}

double Point::Distance(const Point &other) const{
    return std::sqrt(pow((other.GetX() - this->GetX()), 2) + pow((other.GetY() - this->GetY()), 2));
}

void Point::ToString(std::ostream *out) const{
    (*out) << "Coordinates of the point: (" << this->GetX() << "; " << this->GetY() << ")" << std::endl;
}

double Point::GetX() const {
    return x_;
}

double Point::GetY() const {
    return y_;
}

void Point::SetX(double x) {
    this->x_ = x;
}

void Point::SetY(double y) {
    this->y_ = y_;
}
