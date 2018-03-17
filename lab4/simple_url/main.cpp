#include "SimpleUrl.h"


int main() {
    std::vector <std::string> vec = {"mailto:someone@example.com?subject=This%20is%20the%20subject&cc=someone_else@example.com&body=This%20is%20the%20body", "https://en.wikipedia.org/wiki/Uniform_Resource_Locator"};

    //auto firstStr = std::make_unique<nets::SimpleUrl>("mailto:someone@example.com?subject=This%20is%20the%20subject&cc=someone_else@example.com&body=This%20is%20the%20body");
    //auto firstStr = std::make_unique<nets::SimpleUrl>("https://en.wikipedia.org/wiki/Uniform_Resource_Locator");
    auto firstStr = std::make_unique<nets::SimpleUrl>("https://www.google.pl/maps/dir/50.0661704,19.9231828/50.0622998,19.9379993/@50.064617,19.9255421,16z/data=!4m3!4m2!3e2!5i2");
    std::string scheme = firstStr->Scheme();
    std::cout << "SCHEME: " << scheme << std::endl;
    std::string login = firstStr->Login();
    std::cout << "LOGIN: " << login << std::endl;
    std::string host = firstStr->Host();
    std::cout << "HOST: " << host << std::endl;
    uint16_t port = firstStr->Port();
    std::cout << "PORT: " << port << std::endl;
    std::string path = firstStr->Path();
    std::cout << "PATH: " << path << std::endl;
    std::string query = firstStr->Query();
    std::cout << "QUERY: " << query << std::endl;
    std::string fragment = firstStr->Fragment();
    std::cout << "FRAGMENT: " << fragment << std::endl;
    return 0;
}