//
// Created by wingc on 19-6-11.
//

#include "w_string.h"

namespace WingC{
    std::vector<std::string> s_split(const std::string &s, char delim) {
        std::vector<std::string> result;
        WingC::split(s, delim, std::back_inserter(result));
        return result;
    }

    template<typename Out>
    void split(const std::string &s, char delim, Out result) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            if (!item.empty())
                *(result++) = item;
        }
    }

    std::vector<std::string> w_split(const std::string &s, char separator, bool ignore_empty) {
        std::vector<std::string> result;
        std::string::size_type cur_pos = 0, pre_pos = 0;
        while ((cur_pos = s.find(separator, cur_pos)) != std::string::npos) {
            std::string subString(s.substr(pre_pos, cur_pos - pre_pos));
            if (ignore_empty) {
                if (!subString.empty())
                    result.emplace_back(subString);
            }
            else
                result.emplace_back(subString);
            pre_pos = ++cur_pos;
        }
        result.push_back(s.substr(pre_pos, cur_pos - pre_pos));
        return result;
    }
}

