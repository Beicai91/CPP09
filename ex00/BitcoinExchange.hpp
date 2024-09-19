#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <climits>
#include <ctime>
#include <limits>
#include <stdexcept>

class BitcoinExchange
{
    private:
        std::multimap<std::string, double>    _rate;
        void    _createRateMap(std::string fn);
        static bool    _checkDateValidity(std::string date);
        static bool    _checkValueValidity(double value, std::string &err);
        double    _exchange(std::string date, double value);
        static std::string  _trim(std::string &str);
    
    public:
        BitcoinExchange();
        BitcoinExchange(std::string rateFN);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        std::multimap<std::string, double>    getRateMap();

        void    proceedExchange(std::string inputFN);
};

#endif