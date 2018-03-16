#include "TinyUrl.h"

int main() {
    std::array<char, 6> *ptr = new std::array<char, 6> ({'0','9','9','9','9','9'});
    tinyurl::NextHash(ptr);
    for ( int j = 0; j < (*ptr).size(); j++ ) {
        std::cout << (*ptr)[j] << std::endl;
    }

    std::string url = "https://google.com";
    auto myPtr = tinyurl::Init();
    std::string tinyUrl = tinyurl::Encode(url, &myPtr);
    std::cout << "First tiny url: " << tinyUrl << std::endl;
    std::string longUrl = tinyurl::Decode(myPtr, tinyUrl);
    std::cout << "First decode url: " << longUrl << std::endl;
    url = "https://wikipedia.org";
    tinyUrl = tinyurl::Encode(url, &myPtr);
    std::cout << "Second tiny url: " << tinyUrl << std::endl;
    longUrl = tinyurl::Decode(myPtr, tinyUrl);
    std::cout << "Second decode url: " << longUrl << std::endl;
    return 0;
}
