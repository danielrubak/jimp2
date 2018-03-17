#include "Point.h"

::geometry::Point::Point(): x_(0),y_(0) {
    //std::cout << "Non-parametric constructor" << std::endl;
}

::geometry::Point::Point(double x, double y) {
    //std::cout << "Parametric constructor" << std::endl;
    x_ = x;
    y_ = y;
}

::geometry::Point::~Point() {
    //std::cout << "Destructor of the point: (" << this->GetX() << "; " << this->GetY() << ")" << std::endl;
}

double ::geometry::Point::Distance(const ::geometry::Point &other) const{
    return std::sqrt(pow((other.GetX() - this->GetX()), 2) + pow((other.GetY() - this->GetY()), 2));
}

void ::geometry::Point::ToString(std::ostream *out) const{
    (*out) << "Coordinates of the point: (" << this->GetX() << "; " << this->GetY() << ")" << std::endl;
}

double ::geometry::Point::GetX() const {
    return x_;
}

double ::geometry::Point::GetY() const {
    return y_;
}

void ::geometry::Point::SetX(double x) {
    this->x_ = x;
}

void ::geometry::Point::SetY(double y) {
    this->y_ = y_;
}
