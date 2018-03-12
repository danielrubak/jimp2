#include "MinimalTimeDifference.h"

namespace minimaltimedifference {
    unsigned int ToMinutes(std::string time_HH_MM) {
        if ( time_HH_MM.size() < 5 ) {
            time_HH_MM = "0" + time_HH_MM;
        }
        int minutes = 0, hours = 0;
        std::string minutesStr = time_HH_MM.substr(3,2);
        std::istringstream s1(minutesStr);
        s1 >> minutes;
        std::string hoursStr = time_HH_MM.substr(0,2);
        std::istringstream s2(hoursStr);
        s2 >> hours;
        hours *= 60;
        return hours + minutes;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {
        int temp = 1;
        unsigned int minimalTimeDifference = 200000;
        for ( auto i = times.begin(); i != (times.end()-1); i++ ) {
            for (auto j = times.begin()+temp; j != times.end(); j++) {
                unsigned int firstTimeToMinutes = ToMinutes(*i);
                unsigned int secondTimeToMinutes = ToMinutes(*j);
                std::cout << *i << ", " << firstTimeToMinutes << ", " << *(j) << ", " << secondTimeToMinutes << std::endl;

                int firstDifference = 0, secondDifference = 0;
                if ( firstTimeToMinutes >= secondTimeToMinutes ) {
                    firstDifference = firstTimeToMinutes - secondTimeToMinutes;
                    secondDifference = 1440 - firstTimeToMinutes + secondTimeToMinutes;
                } else {
                    firstDifference = secondTimeToMinutes - firstTimeToMinutes;
                    secondDifference = 1440 - secondTimeToMinutes + firstTimeToMinutes;
                }
                std::cout << firstDifference << ", " << secondDifference << std::endl;
                if ( firstDifference < secondDifference ) {
                    if ( firstDifference < minimalTimeDifference )
                        minimalTimeDifference = firstDifference;
                } else {
                    if (  secondDifference < minimalTimeDifference )
                        minimalTimeDifference = secondDifference;
                }

            }
            temp++;
        }
        return minimalTimeDifference;
    }
}

