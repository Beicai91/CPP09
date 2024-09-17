#include "RPN.hpp"

//constructors, destrutor and operator
RPN::RPN(){}

RPN::RPN(const RPN &other)
{
    (void)other;
}

RPN::~RPN(){}

RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return (*this);
}

//other public funcs
void    RPN::process(const std::string &data)
{
    std::stack<int> stk;
    std::string operators = "+-*/";
    int left;
    int right;
 
    size_t i = 0;
    while (i < data.length())
    {
        while (data[i] == ' ')
            i++;
        if (!_checkEle(data[i]))
        {
            std::cerr << "Error: expression not valid" << std::endl;
            return ;
        }
        size_t  pos = operators.find(data[i]);
        if (pos == std::string::npos)
            stk.push(data[i] - '0');
        else
        {
            if (stk.size() >= 2)
            {
                right = stk.top();
                stk.pop();
                left = stk.top();
                stk.pop();
                stk.push(_doMath(left, right, data[i]));
            }
            else
                std::cerr << "Error: expression not valid" << std::endl;
        }
        i++;
    }
    if (stk.size() != 1)
        std::cerr << "Error: expression not valid" << std::endl;
    else
        std::cout << stk.top() << std::endl;
}

//private functions
bool    RPN::_checkEle(char c)
{
    std::string eles = "0123456789+-*/";
    size_t  pos = eles.find(c);
    if (pos == std::string::npos)
        return false;
    else
        return true;
}

int RPN::_doMath(int left, int right, char op)
{
    if (op == '+')
        return (left + right);
    else if (op == '-')
        return (left - right);
    else if (op == '*')
        return (left * right);
    else
        return (left / right);
}