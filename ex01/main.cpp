#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Insufficient arguments" << std::endl;
        return (-1);
    }
    RPN::process(argv[1]);
    return (0);
}