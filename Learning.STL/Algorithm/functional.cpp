#include "functional.h"

Functional::Functional()
{

}

void Functional::test()
{
    vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8};
    Operator<int> op = for_each(test.begin(), test.end(), Operator<int>(Operator<int>::SUM));
    cout << "Use Sum Operate: " << op.value() << endl;
    Operator<int> op2 = for_each(test.begin(), test.end(), Operator<int>(Operator<int>::AVG));
    cout << "Use AVG Operate: " << op2.value() << endl;
}

void Functional::test_compose_f_gx()
{
    vector<int> col;
    for (int i=1; i<=9; ++i) col.push_back(i);

    transform (col.begin(), col.end(),
               ostream_iterator<int>(cout, " "),
               compose_f_gx_t(bind2nd(multiplies<int>(), 5), bind2nd(plus<int>(), 10)));
    PRINT_ELEMENTS(col);
}
