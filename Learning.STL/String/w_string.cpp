//
// Created by wingc on 19-6-11.
//

#include "w_string.h"


std::vector<std::string> s_split(const std::string &s, char delim) {
    std::vector<std::string> result;
    split(s, delim, std::back_inserter(result));
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
