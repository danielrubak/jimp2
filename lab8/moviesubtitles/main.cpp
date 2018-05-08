#include <memory>
#include "MovieSubtitles.h"

int main() {
    auto subs = std::make_unique<moviesubs::SubRipSubtitles>();
    std::stringstream in {"1\n00:00:10,345 --> 00:00:12,678\nTEXT\n\n4\n00:19:14,141 --> 00:21:20,100\nTT\n"};
    std::stringstream out;
    subs->ShiftAllSubtitlesBy(-1140, 25, &in, &out);
    return 0;
}