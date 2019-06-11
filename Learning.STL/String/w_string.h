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


template<typename Out>
void split(const std::string &s, char delim, Out result);
std::vector<std::string> s_split(const std::string &s, char delim);

#endif //LEARNING_STL_W_STRING_H
