#include "MinimalTimeDifference.h"

int main() {
    std::string time_1 = "23:59";
    std::string time_2 = "3:59";
    std::vector<std::string> vec = {"1:00", "23:59", "17:56", "14:13", "15:40"};
    unsigned int answer = minimaltimedifference::MinimalTimeDifference(vec);
    std::cout << answer << std::endl;
    return 0;
}
