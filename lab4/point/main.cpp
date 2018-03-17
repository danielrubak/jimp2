#include "Point.h"

int main() {
    ::geometry::Point p1;
    ::geometry::Point p2 (1, 1);
    p1.ToString(&std::cout);
    p2.ToString(&std::cout);
    double distance_between_points = p1.Distance(p2);
    std::cout << distance_between_points << std::endl;
    return 0;
}