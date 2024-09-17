#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Arguments not sufficient" << std::endl;
        return (-1);
    }
    BitcoinExchange btc("data.csv");
    btc.proceedExchange(argv[1]);
    return (0);
}