#include "algorithm.h"
#include "functional.h"

using namespace std;

class Persons{
public:
    void call(){cout << "I am called" << endl;}
};

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
    return 0;
}
