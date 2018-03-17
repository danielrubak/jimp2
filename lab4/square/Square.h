#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "../point/Point.h"

namespace geometry {
    class Square {
    public:
        Square();
        Square(Point point_1, Point point_2, Point point_3, Point point_4);
        ~Square();
        double Circumference();
        double Area();
    private:
        Point first_coordinate, second_coordinate, third_coordinate, fourth_coordinate;
    };
}


#endif //JIMP_EXERCISES_SQUARE_H
