#include "MovieSubtitles.h"

std::string addOffsetToString (std::string seconds, std::string milliseconds, int offset);

namespace moviesubs
{
    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) {
        if ( frame_per_second <= 0 ) {
            throw std::invalid_argument("At line 0: FPS <= 0");
        }
        const int delay = (offset_in_micro_seconds*frame_per_second)/1000;
        std::string subtitle_line;
        std::stringstream output_subtitle;
        int frame_in_int, frame_out_int;
        int line = 0;
        int prev_frame_end = 0;
        while ( in->peek() != EOF ) {
            line++;
            getline(*in, subtitle_line);
            std::regex pattern ( "\\{(\\d+)\\}\\{(\\d+)\\}(?:\\{([a-z]:[a-zA-Z0-9$]+)\\})?([\\w\\d !|]+)" );
            std::smatch result;
            regex_search( subtitle_line, result, pattern );
            std::string frame_in = result[1];
            std::string frame_out = result[2];
            std::string options = result[3];
            std::string subtitle = result[4];
            if ( frame_in == "" || frame_out == "" ) {
                throw InvalidSubtitleLineFormat(subtitle_line, line);
            }
            std::istringstream (frame_in) >> frame_in_int;
            std::istringstream (frame_out) >> frame_out_int;
            if ( frame_in_int >= frame_out_int ) {
                throw SubtitleEndBeforeStart(subtitle_line, line);
            }
            frame_in_int = frame_in_int + delay;
            frame_out_int = frame_out_int + delay;
            if ( frame_out_int < prev_frame_end ) {
                throw OutOfOrderFrames(subtitle_line, line);
            } else {
                prev_frame_end = frame_out_int;
            }
            if ( frame_in_int < 0 || frame_out_int < 0 ) {
                throw NegativeFrameAfterShift(subtitle_line, line);
            }
            output_subtitle << "{" << frame_in_int << "}{" << frame_out_int << "}";
            if ( options != "" ) {
                output_subtitle << "{" << options << "}";
            }
            output_subtitle << "" << subtitle << "\n";
        }
        std::string final_subtitles = output_subtitle.str();
        *out << final_subtitles;
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) {
        std::string frame_index, subtitle_time, temp_subtitle;
        std::stringstream output_subtitle;
        while ( in->peek() != EOF ) {
            getline(*in, frame_index);
            output_subtitle << "" << frame_index << "\n";
            getline(*in, subtitle_time);
            std::regex pattern ( "(\\d{2}:\\d{2}):(\\d{2}),(\\d{3}) --> (\\d{2}:\\d{2}):(\\d{2}),(\\d{3})" );
            std::smatch result;
            regex_search( subtitle_time, result, pattern );
            std::string start_time = addOffsetToString(result[2], result[3], offset_in_micro_seconds);
            output_subtitle << result[1] << start_time << " --> ";
            std::string end_time = addOffsetToString(result[5], result[6], offset_in_micro_seconds);
            output_subtitle << result[4] << end_time << "\n";
            do {
                getline(*in, temp_subtitle);
                output_subtitle << "" << temp_subtitle << "\n";
            } while ( temp_subtitle != "");
        }
        std::string final_subtitles = output_subtitle.str();
        *out << final_subtitles;
    }

    SubtitlesException::SubtitlesException(std::string &message, int number) : invalid_argument("At line " + std::to_string(number)+ ": " + message )
    { line_number = number; }

    int SubtitlesException::LineAt() const {
        return line_number;
    }

    NegativeFrameAfterShift::NegativeFrameAfterShift(std::string &message, int number) : SubtitlesException(message, number) {}

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(std::string &message, int number) : SubtitlesException(message, number) {}

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(std::string &message, int number) : SubtitlesException(message, number) {}

    OutOfOrderFrames::OutOfOrderFrames(std::string &message, int number) : SubtitlesException(message, number) {}

    MissingTimeSpecification::MissingTimeSpecification(std::string &message, int number) : SubtitlesException(message, number) {}
}

std::string addOffsetToString (std::string seconds, std::string milliseconds, int offset) {
    int temp_1, temp_2;
    std::istringstream (seconds) >> temp_1;
    std::istringstream (milliseconds) >> temp_2;
    if ( temp_2 + offset > 999 ) {
        temp_1 = temp_1 + (temp_2 + offset)/1000;
    }
    temp_2 = (temp_2 + offset)%1000;

    std::string start_seconds = std::to_string(temp_1);
    if (start_seconds.length() == 1) {
        std::string result = "0" + start_seconds;
        start_seconds = result;
    }
    std::string start_milliseconds = std::to_string(temp_2);
    if (start_milliseconds.length() == 1) {
        std::string result = "00" + start_milliseconds;
        start_milliseconds = result;
    } else if (start_milliseconds.length() == 2) {
        std::string result = "0" + start_milliseconds;
        start_milliseconds = result;
    }
    return ":" + start_seconds + "," + start_milliseconds;
}