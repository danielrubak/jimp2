#include "SimpleUrl.h"

nets::SimpleUrl::SimpleUrl() {
}

nets::SimpleUrl::SimpleUrl(std::string url) {
    std::regex url_pattern ( "^(\\w+)\\:\\/*(?:([a-z]+)\\@)?([a-z.-]+)(?:\\:([0-9]+))?(?:\\/([^#^?]*))?(?:\\?([^?^#]+))?(?:\\#(.*))?$" );
    std::smatch url_groups;
    std::regex_search(url, url_groups, url_pattern);

    this->scheme = url_groups[1];
    this->login = url_groups[2];
    this->host = url_groups[3];
    if ( url_groups[4] != "" ) {
        uint16_t port;
        std::istringstream reader(url_groups[4]);
        reader >> port;
        this->port = port;
    } else {
        if ( scheme == "https" )
            this->port = 443;
        else if ( scheme == "http" )
            this->port = 80;
        else if ( scheme == "mailto")
            this->port = 0;
        else if ( scheme == "ftp" )
            this->port = 22;
    }
    this->path = url_groups[5];
    this->query = url_groups[6];
    this->fragment = url_groups[7];
}

nets::SimpleUrl::~SimpleUrl() {

}

std::string nets::SimpleUrl::Scheme() const {
    return this->scheme;
}

std::string nets::SimpleUrl::Login() const {
    return this->login;
}

std::string nets::SimpleUrl::Host() const {
    return this->host;
}

uint16_t nets::SimpleUrl::Port() const {
    return this->port;
}

std::string nets::SimpleUrl::Path() const {
    return this->path;
}

std::string nets::SimpleUrl::Query() const {
    return this->query;
}

std::string nets::SimpleUrl::Fragment() const {
    return this->fragment;
}