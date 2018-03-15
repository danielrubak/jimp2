#include "TinyUrl.h"

std::unique_ptr<tinyurl::TinyUrlCodec> tinyurl::Init() {
    std::unique_ptr<tinyurl::TinyUrlCodec> newStructPointer = std::make_unique<tinyurl::TinyUrlCodec>();
    return newStructPointer;
}

void tinyurl::NextHash(std::array<char, 6> *state) {
    int i = 5;
    bool run = true;
    while ( run ) {
        int ch = (int)(*state)[i];
        if ( ch == 122 ) {
            (*state)[i] = '0';
            i--;
        } else if ( ch == 57 ) {
            (*state)[i] = 'A';
            run = false;
        } else if ( ch == 90 ) {
            (*state)[i] = 'a';
            run = false;
        } else {
            ch++;
            (*state)[i] = (char)ch;
            run = false;
        }
    }
}
