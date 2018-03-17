#include "Square.h"
#include "../point/Point.cpp"

::geometry::Square::Square(): first_coordinate (0,0), second_coordinate(0,0), third_coordinate(0,0), fourth_coordinate(0,0) {
}

::geometry::Square::Square(::geometry::Point point_1, ::geometry::Point point_2, ::geometry::Point point_3, ::geometry::Point point_4) {
    first_coordinate = point_1;
    second_coordinate = point_2;
    third_coordinate = point_3;
    fourth_coordinate = point_4;
}

::geometry::Square::~Square() {
    //std::cout << "Destructor of the point: (" << this->GetX() << "; " << this->GetY() << ")" << std::endl;
}

double ::geometry::Square::Circumference() {
    std::vector<double> sides_lengths;
    sides_lengths.push_back((this->first_coordinate).Distance(this->second_coordinate));
    sides_lengths.push_back((this->second_coordinate).Distance(this->third_coordinate));
    sides_lengths.push_back((this->third_coordinate).Distance(this->fourth_coordinate));
    sides_lengths.push_back((this->fourth_coordinate).Distance(this->first_coordinate));
    sort( sides_lengths.begin(), sides_lengths.end() );
    sides_lengths.erase( unique( sides_lengths.begin(), sides_lengths.end() ), sides_lengths.end() );
    if ( sides_lengths.size() > 2 ) {
        return 0;
    } else {
        return 4*sides_lengths[0];
    }
}

double ::geometry::Square::Area() {
    std::vector<double> sides_lengths;
    sides_lengths.push_back((this->first_coordinate).Distance(this->second_coordinate));
    sides_lengths.push_back((this->second_coordinate).Distance(this->third_coordinate));
    sides_lengths.push_back((this->third_coordinate).Distance(this->fourth_coordinate));
    sides_lengths.push_back((this->fourth_coordinate).Distance(this->first_coordinate));
    sort( sides_lengths.begin(), sides_lengths.end() );
    sides_lengths.erase( unique( sides_lengths.begin(), sides_lengths.end() ), sides_lengths.end() );
    if ( sides_lengths.size() > 2 ) {
        return 0;
    } else {
        return std::pow(sides_lengths[0], 2);
    }
}