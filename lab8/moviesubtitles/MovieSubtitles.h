#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <sstream>
#include <iostream>
#include <regex>
#include <stdexcept>

namespace moviesubs
{
    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) = 0;
        ~MovieSubtitles() = default;
    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) override;
    };

    class SubRipSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) override;
    };

    class SubtitlesException : public std::invalid_argument {
    public:
        SubtitlesException (std::string &message, int number);
        int LineAt() const;
    private:
        int line_number;
    };

    class NegativeFrameAfterShift : public SubtitlesException {
    public:
        NegativeFrameAfterShift(std::string &message, int number);
    };

    class SubtitleEndBeforeStart : public SubtitlesException {
    public:
        SubtitleEndBeforeStart(std::string &message, int number);
    };

    class InvalidSubtitleLineFormat : public SubtitlesException {
    public:
        InvalidSubtitleLineFormat(std::string &message, int number);
    };

    class OutOfOrderFrames : public SubtitlesException {
    public:
        OutOfOrderFrames(std::string &message, int number);
    };

    class MissingTimeSpecification : public SubtitlesException {
    public:
        MissingTimeSpecification(std::string &message, int number);
    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H