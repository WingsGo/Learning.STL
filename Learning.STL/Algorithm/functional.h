#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include "algorithm.h"
#include <functional>
#include <vector>

using namespace std;

template <class OP1, class OP2>
class compose_f_gx : public unary_function<typename OP2::argument_type, typename OP1::result_type>{
private:
    OP1 m_op1;
    OP2 m_op2;

public:
    compose_f_gx(const OP1& op1, const OP2& op2): m_op1(op1), m_op2(op2){}
    typename OP1::result_type operator ()(const typename OP2::argument_type& x) {
        return m_op1(m_op2(x));
    }
};

template <class OP1, class OP2>
inline compose_f_gx<OP1, OP2> compose_f_gx_t(const OP1& op1, const OP2& op2)
{
    return compose_f_gx<OP1, OP2>(op1, op2);
}

template <typename T>
class Operator{
public:
    enum Rule{SUM, AVG};

private:
    T m_sum;
    int m_count;
    Rule m_rule;

public:
    explicit Operator(Rule rule=Rule::SUM) : m_sum(0), m_count(0), m_rule(rule){}

    void operator ()(T t)
    {
        m_sum += t;
        m_count++;
    }

    double value()
    {
        if (m_rule == Rule::SUM)
            return m_sum;
        else {
            return (m_count == 0) ? 0 : (m_sum / m_count);
        }
    }
};

class Functional
{
public:
    Functional();

    void test();
    void test_compose_f_gx();
};

#endif // FUNCTIONAL_H
