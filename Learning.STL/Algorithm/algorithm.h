//
// Created by wingc on 19-6-11.
//

#ifndef LEARNING_STL_ALGORITHM_H
#define LEARNING_STL_ALGORITHM_H

#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <vector>
#include <set>
#include <string>
#include <functional>

class AddValue;

class Algorithm
{
public:
    Algorithm();

    void test_remove();
    void test_erase();

    void test_list_remove();

    void test_transform();

    void test_predicate();
    void test_sort();

    void test_addValue();

};

template<class T>
inline void PRINT_ELEMENTS(const T& container, const char* start="")
{
    typename T::const_iterator pos;

    std::cout << start;

    for (pos=container.begin(); pos!=container.end(); ++pos)
        std::cout << *pos << " ";
    std::cout << std::endl;
}

inline bool isPrime(int number)
{
    number = abs(number);

    if (number==0 || number==1)
        return true;

    int divisor;
    for (divisor=sqrt(number); number%divisor != 0; --divisor){}
    return divisor == 1;
}

class AddValue{
public:
    AddValue(int addValue) : value(addValue){}
    void operator ()(int& inputValue)
    {
        inputValue += value;
    }

private:
    int value;
};

class Person{
public:
    explicit Person(const std::string &a, const std::string &b)
            :first_name(a), second_name(b){}

    std::string firstName() const {return std::string(first_name);}
    std::string secondName() const {return std::string(second_name);}

    Person& operator=(const Person& p)
    {
        this->first_name = p.firstName();
        this->second_name = p.secondName();
        return *this;
    }

private:
    std::string first_name;
    std::string second_name;
};

inline bool compareName(const Person& p1, const Person& p2)
{
    return (p1.secondName() < p2.secondName()) || (!(p1.secondName() < p2.secondName()) && p1.firstName() < p2.firstName());
}

#endif //LEARNING_STL_ALGORITHM_H
