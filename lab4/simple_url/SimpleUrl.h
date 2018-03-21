#ifndef JIMP_EXERCISES_SIMPLEURL_H
#define JIMP_EXERCISES_SIMPLEURL_H

#include <string>
#include <iostream>
#include <cstdint>
#include <vector>
#include <regex>
#include <sstream>
#include <algorithm>

namespace nets {
    class SimpleUrl {
    public:
        SimpleUrl();
        SimpleUrl(std::string url);
        ~SimpleUrl();
        std::string Login() const;
        std::string Host() const;
        std::string Path() const;
        uint16_t Port() const;
        std::string Scheme() const;
        std::string Query() const;
        std::string Fragment() const;
    private:
        std::string scheme;
        std::string login;
        std::string host;
        uint16_t port;
        std::string path;
        std::string query;
        std::string fragment;
    };
}

#endif //JIMP_EXERCISES_SIMPLEURL_H
