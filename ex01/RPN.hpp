#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <string>

class RPN
{
    private:
        static int _doMath(int left, int right, char op);
        static bool _checkEle(char c);
    
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        static void    process(const std::string &data);   
};

#endif