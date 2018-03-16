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

std::string tinyurl::Encode(const std::string &url, std::unique_ptr<tinyurl::TinyUrlCodec> *codec) {
    NextHash( &(codec->get()->hashArray) );
    std::string tinyUrl = "";
    for ( int i = 0; i < 6; i++ ) {
        tinyUrl += codec->get()->hashArray[i];
    }
    codec->get()->urlToTinyUrlMap.insert( std::pair<std::string, std::string> (tinyUrl, url) );
    return tinyUrl;
}

std::string tinyurl::Decode(const std::unique_ptr<tinyurl::TinyUrlCodec> &codec, const std::string &hash) {
    auto iter = codec->urlToTinyUrlMap.find(hash);
    if ( iter == codec->urlToTinyUrlMap.end() ) {
        return "";
    } else
        return (*iter).second;
}
