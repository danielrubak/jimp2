#include "MovieSubtitles.h"

namespace moviesubs
{
    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) {
        if ( frame_per_second <= 0 ) {
            throw std::invalid_argument("At line 0: FPS <= 0");
        }
        const int delay = (offset_in_micro_seconds*frame_per_second)/1000;
        //std::cout << "DELAY: " << delay << std::endl;
        std::string subtitle_line;
        std::stringstream output_subtitle;
        int frame_in_int, frame_out_int;
        int line = 0;
        int prev_frame_end = -1;
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
            //std::cout << prev_frame_end <<", " << frame_in_int << ", " << frame_out_int << std::endl;
            if ( frame_in_int < prev_frame_end ) {
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
            output_subtitle << subtitle << "\n";
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
}