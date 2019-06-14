#include "Algorithm/algorithm.h"
#include "Algorithm/functional.h"

#include "String/w_string.h"
#include "Utils/utils.h"

using namespace std;

class Persons{
public:
    void call(){cout << "I am called" << endl;}
};

const char* cast() {
    std::string result("test cast");
    return result.c_str();
}

int main(int argc, char *argv[])
{
    Functional func;
    func.test();
    cout << "test compose" << endl;
    func.test_compose_f_gx();
    vector<int> v(12);
    cout << "capacity V" <<v.capacity();
    vector<int> tmp(9);
    v.swap(tmp);
    cout << "capacity V" <<v.capacity();

    Algorithm al;
    al.test_addValue();

    vector<int> t(v.begin(), v.begin()+3);
    PRINT_ELEMENTS(t);

    std::string test_string("this,,,is,a,test");
    auto a = WingC::w_split(test_string, ',', false);
    for (const auto& i : a) {
        std::cout << i << std::endl;
    }

    WingC::foo();

    return 0;
}
