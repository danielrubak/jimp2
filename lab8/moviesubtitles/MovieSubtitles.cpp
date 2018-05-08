#include "MovieSubtitles.h"

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
        if ( frame_per_second <= 0 ) {
            throw std::invalid_argument("At line 0: FPS <= 0");
        }
        std::string frame_index, subtitle_time, temp_subtitle;
        std::stringstream output_subtitle;
        int actual_frame;
        int prev_frame = 0;
        int line = 0;
        while ( in->peek() != EOF ) {
            line++;
            getline(*in, frame_index);
            std::istringstream (frame_index) >> actual_frame;
            if ( (prev_frame + 1) != actual_frame ) {
                throw OutOfOrderFrames(frame_index, line);
            } else {
                prev_frame = actual_frame;
            }
            actual_frame++;
            output_subtitle << "" << frame_index << "\n";
            getline(*in, subtitle_time);
            std::regex pattern("(\\d{2}:\\d{2}:\\d{2},\\d{3}) --> (\\d{2}:\\d{2}:\\d{2},\\d{3})");
            std::smatch result;
            regex_search(subtitle_time, result, pattern);
            if ( result[0] == "" ) {
                std::string msg = "Invalid time format";
                throw InvalidSubtitleLineFormat(msg, line);
            }
            if ( result[2].compare(result[1]) < 0 ) {
                std::string msg = result[0];
                throw SubtitleEndBeforeStart(msg, line);
            }
            std::string start_time = addOffsetToString(result[1], offset_in_micro_seconds, line);
            std::string end_time = addOffsetToString(result[2], offset_in_micro_seconds, line);
            output_subtitle << "" << start_time << " --> " << end_time << "\n";
            do {
                getline(*in, temp_subtitle);
                output_subtitle << "" << temp_subtitle << "\n";
            } while ( temp_subtitle != "");
        }
        std::string final_subtitles = output_subtitle.str();
        *out << final_subtitles;
    }

    std::string addOffsetToString (std::string t, int offset, int line) {
        int h, m, s, ms = 0;
        int m_new, s_new, ms_new = 0;
        std::string h_str, m_str, s_str, ms_str;
        if ( sscanf(t.c_str(), "%d:%d:%d,%d", &h, &m, &s, &ms ) >= 2)
        {
            if ( offset < 0 ) {
                ms_new = (ms + offset)%1000;
                if ( ms_new < 0 && s > 0 ) {
                    ms_new = 1000 + ms_new;
                }
                if ( offset + ms < -1000 ) {
                    s_new = s + (offset/1000) - 1;
                } else {
                    s_new = s + (offset/1000);
                }
                if ( s_new < 0 && m > 0 ) {
                    s_new = 60 + s_new;
                }
                m_new = m + (s + offset)/60000;
                if ( m_new < 0 && h > 0 ) {
                    m_new = 60 + m_new;
                }
                h = h + (m+ offset)/3600000;
                ms = ms_new;
                s = s_new;
                m = m_new;
                if ( h < 0 || m < 0 || s < 0 || ms < 0 ) {
                    throw NegativeFrameAfterShift(t, line);
                }

            } else {
                h = h + (m+ offset)/3600000;
                m = m + (s + offset)/60000;
                s = s + (ms + offset)/1000;
                ms = (ms + offset)%1000;
                h_str = std::to_string(h);
                if ( h_str.length() == 1 ) {
                    std::string result = "0" + h_str;
                    h_str = result;
                }
                m_str = std::to_string(m);
                if ( m_str.length() == 1 ) {
                    std::string result = "0" + m_str;
                    m_str = result;
                }
                s_str = std::to_string(s);
                if ( s_str.length() == 1 ) {
                    std::string result = "0" + s_str;
                    s_str = result;
                }
                ms_str = std::to_string(ms);
                if ( ms_str.length() == 1 ) {
                    std::string result = "00" + ms_str;
                    ms_str = result;
                } else if ( ms_str.length() == 2 ) {
                    std::string result = "0" + ms_str;
                    ms_str = result;
                }
            }
        }
        return h_str + ":" + m_str + ":" + s_str + "," + ms_str;
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