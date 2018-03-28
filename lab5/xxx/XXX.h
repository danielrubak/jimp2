#ifndef JIMP2_XXX_H
#define JIMP2_XXX_H

#include <string>
#include <cstring>
#include <algorithm>
using ::std::swap;

class XXX {
public:
    XXX();
    XXX(int param);
    XXX(const std::string name);
    XXX(const XXX &xxx);
    XXX(XXX &&xxx);
    XXX &operator=(const XXX &xxx);
    XXX &operator=(XXX &&xxx);
    ~XXX();
private:
    char *name_;
};

#endif //JIMP2_XXX_H
