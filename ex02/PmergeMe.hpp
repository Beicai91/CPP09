#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
#include <chrono>

class PmergeMe
{
    private:
        static void _sortVec(std::vector<int> &vec, int start, int end);
        static void _mergeVec(std::vector<int> &vec, int start, int mid, int end);
        static void _insertionSortVec(std::vector<int> &vec, int start, int end);
        static void _sortDeque(std::deque<int> &dec, int start, int end);
        static void _mergeDeque(std::deque<int> &dec, int start, int mid, int end);
        static void _insertionSortDeque(std::deque<int> &dec, int start, int end);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe    &operator=(const PmergeMe &other);
        ~PmergeMe();

        static std::vector<int> MI_sort_vector(std::string input);
        static std::deque<int> MI_sort_deque(std::string input);
};

typedef std::chrono::high_resolution_clock::time_point tp;
typedef std::chrono::duration<double, std::micro> dur;   

#endif