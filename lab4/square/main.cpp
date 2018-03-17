#include "Square.h"

int main() {
    ::geometry::Point point_1 {0, 1};
    ::geometry::Point point_2 {0, 0};
    ::geometry::Point point_3 {1, 1};
    ::geometry::Point point_4 {1, 0};
    ::geometry::Square square_1 (point_1, point_2, point_3, point_4);
    double circumference = square_1.Square::Circumference();
    std::cout << "Circumference: " << circumference << std::endl;
    double area = square_1.Square::Area();
    std::cout << "Area: " << area << std::endl;
    return 0;
}