#ifndef PROJECTNAME_PATH_POINT_H_
#define PROJECTNAME_PATH_POINT_H_

#include <iostream>
#include <cmath>

namespace  geometry {
    class Point {
    public:
        Point();
        Point(double x, double y);
        ~Point();
        double Distance(const Point &other) const;
        void ToString(std::ostream *out) const;
        double GetX() const;
        double GetY() const;
        void SetX(double x);
        void SetY(double y);
    private:
        double x_, y_;
    };
}


#endif  // PROJECTNAME_PATH_POINT_H_