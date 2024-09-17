#include "BitcoinExchange.hpp"

//constructors, destructor and operators
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string rateFN)
{
    this->_createRateMap(rateFN);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _rate(other._rate)
{
    //the copy assignment operator of map performs deep copy
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this == &other)
        return (*this);
    //clear existing maps
    this->_rate.clear();
    this->_rate = other._rate;
    return (*this);
}

//private functions
void    BitcoinExchange::_createRateMap(std::string fn)
{
    std::string line;
    std::string date;
    double   rate;

    std::ifstream   file(fn);
    if (!file.is_open())
    {
        std::cerr << "Could not open data file" << std::endl;
        return ;
    }
    while (std::getline(file, line))
    {
        if (line.compare("date,exchange_rate") == 0)
            continue ;
        std::istringstream  ss(line);
        if (std::getline(ss, date, ',') && ss >> rate)
            this->_rate.insert(std::make_pair(date, rate));
    }
    file.close();
}

bool    BitcoinExchange::_checkValueValidity(double value, std::string &err)
{
    if (value < 0)
    {
        err = "not a positive number.";
        return false;
    }
    if (value > 1000)
    {
        err = "too large a number.";
        return false;
    }
    return true;
}

bool    BitcoinExchange::_checkDateValidity(std::string date)
{
    int year;
    int month;
    int day;
    char    delimiter1;
    char    delimiter2;

    std::istringstream  ss(date);
    if (ss >> year >> delimiter1 >> month >> delimiter2 >> day)
    {
        if (delimiter1 != '-' || delimiter2 != '-')
            return false;
    }
    std::tm dateStruct = {};
    dateStruct.tm_year = year - 1900;
    dateStruct.tm_mon = month - 1;
    dateStruct.tm_mday = day;
    if (std::mktime(&dateStruct) == -1) //if the date after adjustment is valid but is too far in the past or future (roughly out of range 1901-2038), the return value is -1
        return false;
    //mktime() adjusts out-of-range values for fields like months or days to make them valid. So we check if their values after normalization still correspond to the original one
    if (dateStruct.tm_year != year - 1900 || dateStruct.tm_mon != month - 1 || dateStruct.tm_mday != day)
        return false;
    return true;
}

double   BitcoinExchange::_exchange(std::string date, double value)
{
    double res;

    std::multimap<std::string, double>::iterator  itR = this->_rate.find(date);
    if (itR == this->_rate.end())
    {
        itR = this->_rate.upper_bound(date); //upper_bound() returns the very first key that is greater than the target key
        if (itR != this->_rate.begin())
            itR--;
    }
    res = itR->second * value;
    return (res);
}

//other public functions
void    BitcoinExchange::proceedExchange(std::string inputFN)
{
    std::string line;
    std::string date;
    std::string valueStr;
    double   value;
    std::string err;

    std::ifstream   file(inputFN);
    if (!file.is_open())
    {
        std::cerr << "Could not open input file" << std::endl;
        return ;
    }
    while (std::getline(file, line))
    {
        if (line.compare("date | value") == 0)
            continue ;
        size_t  delimiterPos = line.find('|');
        if (delimiterPos == std::string::npos || delimiterPos == line.length() - 1)
        {
            std::cout << "Error: bad format line. Line format should be \'date | value\'" << std::endl;
            continue ;
        }
        date = line.substr(0, delimiterPos - 1);
        if (!_checkDateValidity(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue ;
        }
        value = std::stod(line.substr(delimiterPos + 2));
        if (!_checkValueValidity(value, err))
        {
            std::cout << "Error: " << err << std::endl;
            continue ;
        }
        std::cout << date << " => " << value << " = " << this->_exchange(date, value) << std::endl;
    }
}

//getters
std::multimap<std::string, double>    BitcoinExchange::getRateMap()
{
    return (this->_rate);
}