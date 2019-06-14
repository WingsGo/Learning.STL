//
// Created by 10189 on 2019/6/13.
//

#ifndef LEARNING_STL_UTILS_H
#define LEARNING_STL_UTILS_H

#include <utility>
#include <string>
#include <tuple>
#include <memory>
#include <numeric>
#include <limits>
#include <climits>

namespace WingC {
    void f1(std::pair<int ,const char*> p1);
    void g1(std::pair<const int, std::string> p2);
    void testPair();

    void testAutoPtr();

    void testNumericalLimits();

    bool intPtrLess(int* a, int* b);
    void testStdMaxMin();

    class TestOps {
    public:
        bool operator == (const TestOps& lhs) const;
        bool operator < (const TestOps& lhs) const;

    };
    void testRelOps();
}

#endif //LEARNING_STL_UTILS_H
