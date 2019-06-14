//
// Created by 10189 on 2019/6/13.
//

#include "utils.h"
#include <iostream>

void WingC::testPair() {
    WingC::f1(std::make_pair(1, "hello"));
    WingC::g1(std::make_pair(2, "hello"));

}

void WingC::f1(std::pair<int, const char *> p1) {

}

void WingC::g1(std::pair<const int, std::string> p2) {

}

void WingC::testAutoPtr() {
    // auto_ptr禁止使用赋值操作完成初始化
    // auto_ptr实际是控制权的转移
    // auto_ptr不能用于vector等STL容器,因为copy与assign运算符会转移对象的所有权
    class A{};
    std::auto_ptr<A> ptr(new A);
}

void WingC::testNumericalLimits() {
    std::cout << "max int " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "min int " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "max short " << std::numeric_limits<short>::max() << std::endl;
    std::cout << "min short " << std::numeric_limits<short>::min() << std::endl;
    std::cout << "max long " << std::numeric_limits<long>::max() << std::endl;
    std::cout << "min long " << std::numeric_limits<long>::min() << std::endl;
}

bool WingC::intPtrLess(int *a, int *b) {
    return *a < *b;
}

void WingC::testStdMaxMin() {
    int x = 17;
    int y = 42;
    int *px = &x;
    int *py = &y;
    int *pmax;
    pmax = std::max(px, py, WingC::intPtrLess);
    std::cout << "pmax use intPtrLess is: " << *pmax << std::endl;
}

void WingC::testRelOps() {
    using namespace std::rel_ops;
    TestOps t1, t2;
    if (t1 != t2) {
        std::cout << "Test Ops != " << std::endl;
    }
    if (t1 > t2) {
        std::cout << "Test Ops > " << std::endl;
    }
}

bool WingC::TestOps::operator<(const WingC::TestOps &lhs) const {
    return false;
}

bool WingC::TestOps::operator==(const WingC::TestOps &lhs) const {
    return false;
}
