#include "PmergeMe.hpp"

//constructor, destructor and operator
PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other;
}
PmergeMe::~PmergeMe(){}
PmergeMe    &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return (*this);
}

//other private functions
void    PmergeMe::_sortVec(std::vector<int> &vec, int start, int end)
{
    if (end - start > 5)
    {
        int mid = (start + end) / 2;
        _sortVec(vec, start, mid);
        _sortVec(vec, mid + 1, end);
        _mergeVec(vec, start, mid, end);
    }
    else
        _insertionSortVec(vec, start, end);
}

void    PmergeMe::_sortDeque(std::deque<int> &dec, int start, int end)
{
    if (end - start > 5)
    {
        int mid = (start + end) / 2;
        _sortDeque(dec, start, mid);
        _sortDeque(dec, mid + 1, end);
        _mergeDeque(dec, start, mid, end);
    }
    else
        _insertionSortDeque(dec, start, end);
}

void    PmergeMe::_insertionSortVec(std::vector<int> &vec, int start, int end)
{
    for (int i = start; i < end; ++i)
    {
        int j = i + 1;
        int tmpVal = vec[j];
        while (j > start && vec[j - 1] > tmpVal)
        {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = tmpVal;
    }
    //test
    //std::cout << "Inside Insertion Sort" << std::endl;
    //std::cout << "Round: start " << start << " end " << end << std::endl;
    //std::cout << "result" << std::endl;
    //for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        //std::cout << *it << " ";
    //std::cout << std::endl;
    //
}

void    PmergeMe::_insertionSortDeque(std::deque<int> &dec, int start, int end)
{
    for (int i = start; i < end; ++i)
    {
        int j = i + 1;
        int tmpVal = dec[j];
        while (j > start && dec[j - 1] > tmpVal)
        {
            dec[j] = dec[j - 1];
            j--;
        }
        dec[j] = tmpVal;
    }
    //test
    //std::cout << "Inside Insertion Sort" << std::endl;
    //std::cout << "Round: start " << start << " end " << end << std::endl;
    //std::cout << "result" << std::endl;
    //for (std::deque<int>::iterator it = dec.begin(); it != dec.end(); ++it)
        //std::cout << *it << " ";
    //std::cout << std::endl;
    //
}

void    PmergeMe::_mergeVec(std::vector<int> &vec, int start, int mid, int end)
{
    std::vector<int>    left;
    std::vector<int>    right;

    //test
    //std::cout << "Inside Merge" << std::endl;
    //std::cout << "Round start " << start << " mid " << mid << " end " << end << std::endl;
    //
    left.assign(vec.begin() + start, vec.begin() + mid + 1);
    right.assign(vec.begin() + mid + 1, vec.begin() + end + 1);
    //test
    //std::cout << "left" << std::endl;
    //for (std::vector<int>::iterator it = left.begin(); it != left.end(); ++it)
        //std::cout << *it << " ";
    //std::cout << std::endl;
    //std::cout << "right" << std::endl;
    //for (std::vector<int>::iterator it = right.begin(); it != right.end(); ++it)
        //std::cout << *it << " ";
    //std::cout << std::endl;
    //
    int l = 0;
    int r = 0;
    int i = start;
    while (l <= mid - start && r <= end - mid - 1)
    {
        if (left[l] < right[r])
        {
            vec[i] = left[l];
            l++;
        }
        else
        {
            vec[i] = right[r];
            r++;
        }
        i++;
    }
    while (l <= mid - start)
    {
        vec[i] = left[l];
        i++;
        l++;
    }
    while (r <= end - mid - 1)
    {
        vec[i] = right[r];
        i++;
        r++;
    }
}

void    PmergeMe::_mergeDeque(std::deque<int> &dec, int start, int mid, int end)
{
    std::deque<int>    left;
    std::deque<int>    right;

    //test
    //std::cout << "Inside Merge" << std::endl;
    //std::cout << "Round start " << start << " mid " << mid << " end " << end << std::endl;
    //
    left.assign(dec.begin() + start, dec.begin() + mid + 1);
    right.assign(dec.begin() + mid + 1, dec.begin() + end + 1);
    //test
    //std::cout << "left" << std::endl;
    //for (std::deque<int>::iterator it = left.begin(); it != left.end(); ++it)
        //std::cout << *it << " ";
    //std::cout << std::endl;
    //std::cout << "right" << std::endl;
    //for (std::deque<int>::iterator it = right.begin(); it != right.end(); ++it)
        //std::cout << *it << " ";
    //std::cout << std::endl;
    //
    int l = 0;
    int r = 0;
    int i = start;
    while (l <= mid - start && r <= end - mid - 1)
    {
        if (left[l] < right[r])
        {
            dec[i] = left[l];
            l++;
        }
        else
        {
            dec[i] = right[r];
            r++;
        }
        i++;
    }
    while (l <= mid - start)
    {
        dec[i] = left[l];
        i++;
        l++;
    }
    while (r <= end - mid - 1)
    {
        dec[i] = right[r];
        i++;
        r++;
    }
}

//other public functions
std::vector<int>    PmergeMe::MI_sort_vector(std::string input)
{
    std::vector<int> nums;
    std::istringstream  ss(input);
    int ele;

    while (ss >> ele)
        nums.push_back(ele);
    //test
    //std::cout << "Before sorting" << std::endl;
    //for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        //std::cout << *it << " ";
    //std::cout << std::endl;
    //
    _sortVec(nums, 0, nums.size() - 1);
    //test
    //std::cout << "Sorted numbers" << std::endl;
    //for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        //std::cout << *it << " ";
    //std::cout << std::endl;
    //
    return (nums);
}

std::deque<int>    PmergeMe::MI_sort_deque(std::string input)
{
    std::deque<int> nums;
    std::istringstream  ss(input);
    int ele;

    while (ss >> ele)
        nums.push_back(ele);
    _sortDeque(nums, 0, nums.size() - 1);
    //test
    //std::cout << "Sorted numbers" << std::endl;
    //for (std::deque<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        //std::cout << *it << " ";
    //std::cout << std::endl;
    //
    return (nums);
}