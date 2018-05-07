#include <memory>
#include "MovieSubtitles.h"

int main() {
    auto subs = std::make_unique<moviesubs::MicroDvdSubtitles>();
    std::stringstream in {"{0}{250}TEXT\n{260}{300}NEWLINE\n{280}{350} Longer text of subtitles"};
    std::stringstream out;
    subs->ShiftAllSubtitlesBy(300, 25, &in, &out);
    return 0;
}