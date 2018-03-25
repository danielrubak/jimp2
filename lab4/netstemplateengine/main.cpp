#include "SimpleTemplateEngine.h"

int main() {
    nets::View view{"Test {{test}} missing:{{missing}}:missing"};
    std::string temp = view.Render({{"test", "replacement"}});
    return 0;
}
