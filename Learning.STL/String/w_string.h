//
// Created by wingc on 19-6-11.
//

#ifndef LEARNING_STL_W_STRING_H
#define LEARNING_STL_W_STRING_H

#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>

namespace WingC {
    template<typename Out>
    void split(const std::string &s, char delim, Out result);
    std::vector<std::string> s_split(const std::string &s, char delim);
    std::vector<std::string> w_split(const std::string& s, char separator, bool ignore_empty = false);
}


#endif //LEARNING_STL_W_STRING_H
