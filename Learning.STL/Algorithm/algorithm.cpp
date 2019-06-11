//
// Created by wingc on 19-6-11.
//

#include "algorithm.h"

using namespace std;

Algorithm::Algorithm()
{

}

void Algorithm::test_remove()
{
    std::list<int> a;
    for (int i=1; i<=6; ++i) {
        a.push_front(i);
        a.push_back(i);
    }

    auto end = std::remove(a.begin(), a.end(), 3);
    std::cout << "移除后元素不变，大小为：" << a.size() << std::endl;

    std::cout << "remove后元素为：";
    std::for_each(a.begin(), a.end(), [](int &a){std::cout << a << " ";});
    std::cout << std::endl;

    std::cout << "删除元素个数为" << distance(end, a.end()) << endl;

    a.erase(end, a.end());
    std::cout << "erase后元素为：";
    std::for_each(a.begin(), a.end(), [](int &a){std::cout << a << " ";});
    std::cout << std::endl;


}

void Algorithm::test_erase()
{
    set<int> col;
    for (int i=1; i<=9; ++i)
        col.insert(i);

    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int num = col.erase(3);

    cout << "num of remove elems" << num << endl;

    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void Algorithm::test_list_remove()
{
    list<int> col;

    for (int i=0; i<=6; ++i) {
        col.push_front(i);
        col.push_back(i);
    }

    // bad performance
    col.erase(remove(col.begin(), col.end(), 3), col.end());
    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // good performance
    col.remove(4);
    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void Algorithm::test_transform()
{
    set<int> col;
    vector<int> col2;

    for (int i=1; i<=9; ++i) {
        col.insert(i);
    }
    PRINT_ELEMENTS(col, "init: ");

    transform(col.begin(), col.end(), back_inserter(col2),
              [](int value){return value * value;});
    PRINT_ELEMENTS(col2, "transform: ");
}

void Algorithm::test_predicate()
{
    list<int> col;

    for (int i=24; i<=30; ++i) col.push_back(i);

    auto pos = find_if(col.begin(), col.end(), isPrime);

    if (pos != col.end())
        cout << "first prime found is " << *pos;
    else
        cout << "not found";
}

void Algorithm::test_sort()
{

}

void Algorithm::test_addValue()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    for_each(a.begin(), a.end(), AddValue(*a.begin()));
    PRINT_ELEMENTS(a);
}
