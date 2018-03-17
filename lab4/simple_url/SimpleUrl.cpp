#include "SimpleUrl.h"

nets::SimpleUrl::SimpleUrl() : urlAddress("") {
}

nets::SimpleUrl::SimpleUrl(std::string url) {
    this->urlAddress = url;
}

std::string nets::SimpleUrl::GetUrl() const {
    return this->urlAddress;
}

std::string nets::SimpleUrl::Login() const {
    std::regex login_pattern(":([A-Za-z0-9]+)@");
    std::smatch login_match_result;
    std::string url = this->GetUrl();
    if ( std::regex_search(url, login_match_result, login_pattern) ) {
        std::string str = login_match_result[0];
        str.erase(std::remove(str.begin(), str.end(), ':'), str.end());
        str.erase(std::remove(str.begin(), str.end(), '@'), str.end());
        return str;
    } else {
        return "";
    }
}

std::string nets::SimpleUrl::Host() const {
    std::regex host_pattern("(@{1}([a-zA-Z0-9.]+)?)|(:/{2}([a-zA-Z0-9.-]+)/?)");
    std::smatch host_match_result;
    std::string url = this->GetUrl();
    if ( std::regex_search(url, host_match_result, host_pattern) ) {
        std::string str = host_match_result[0];
        str.erase(std::remove(str.begin(), str.end(), ':'), str.end());
        str.erase(std::remove(str.begin(), str.end(), '/'), str.end());
        str.erase(std::remove(str.begin(), str.end(), '@'), str.end());
        return str;
    } else {
        return "";
    }
}

std::string nets::SimpleUrl::Path() const {
    std::regex path_pattern("([a-z]/[a-zA-Z0-9_.-:!=,@]*)");
    std::smatch path_match_result;
    std::string url = this->GetUrl();
    if ( std::regex_search(url, path_match_result, path_pattern) ) {
        std::string str = path_match_result[0];
        str.erase(0,2);
        return str;
    } else {
        return "";
    }
}

uint16_t nets::SimpleUrl::Port() const {
    std::string scheme = this->Scheme();
    if ( scheme == "https" ) {
        return 443;
    } else if ( scheme == "http" ) {
        return 80;
    } else if ( scheme == "mailto") {
        return 0;
    } else if ( scheme == "ftp" ) {
        std::regex port_pattern("(:[0-9]+");
        std::smatch port_match_result;
        std::string url = this->GetUrl();
        if ( std::regex_search(url, port_match_result, port_pattern) ) {
            std::string str = port_match_result[0];
            uint16_t port;
            str.erase(std::remove(str.begin(), str.end(), ':'), str.end());;
            std::istringstream reader(str);
            reader >> port;
            return port;
        } else {
            return 22;
        }
    }
}

std::string nets::SimpleUrl::Scheme() const {
    std::regex scheme_pattern("([A-Za-z][A-Za-z0-9+.-]*):");
    std::smatch scheme_match_result;
    std::string url = this->GetUrl();
    if ( std::regex_search(url, scheme_match_result, scheme_pattern) ) {
        std::string str = scheme_match_result[0];
        str.erase(std::remove(str.begin(), str.end(), ':'), str.end());
        return str;
    } else {
        return "";
    }
}

std::string nets::SimpleUrl::Query() const {
    std::regex query_pattern(R"(\?{1}([a-z]*)=([a-zA-Z0-9=%&_@.]*))");
    std::smatch query_match_result;
    std::string url = this->GetUrl();
    if ( std::regex_search(url, query_match_result, query_pattern) ) {
        std::string str = query_match_result[0];
        str.erase(0,1);
        return str;
    } else {
        return "";
    }
}

std::string nets::SimpleUrl::Fragment() const {
    std::regex fragment_pattern("(#{1}[a-zA-Z0-9!/_]*)");
    std::smatch fragment_match_result;
    std::string url = this->GetUrl();
    if ( std::regex_search(url, fragment_match_result, fragment_pattern) ) {
        std::string str = fragment_match_result[0];
        str.erase(0,1);
        return str;
    } else {
        return "";
    }

}