#include "PmergeMe.hpp"
#include <chrono>

bool    checkArg(char *arg)
{
    int i = 0;
    if (arg[i] == '+')
    {
        i++;
        if (arg[i] == '\0')
            return (false);
    }
    while (arg[i])
    {
        if (arg[i] < '0' || arg[i] > '9')
            return (false);
        i++;
    }
    return (true);
}

int main(int argc, char *argv[])
{
    std::string input = "";
    std::vector<int>    res1;
    std::deque<int> res2;

    if (argc < 2)
    {
        std::cerr << "Insufficient argument" << std::endl;
        return (-1);
    }
    int i = 1;
    while (argv[i])
    {
        if (!checkArg(argv[i]))
        {
            std::cerr << "Invalid argument" << std::endl;
            return (-1);
        }
        input += argv[i];
        input += " ";
        i++;
    }
    tp    start1 = std::chrono::high_resolution_clock::now();
    res2 = PmergeMe::MI_sort_deque(input);
    tp    end1 = std::chrono::high_resolution_clock::now();
    tp    start2 = std::chrono::high_resolution_clock::now();
    res1 = PmergeMe::MI_sort_vector(input);
    tp    end2 = std::chrono::high_resolution_clock::now();
    dur    durationDeque = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    dur    durationVector = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

    std::cout << "Before: " << input << std::endl;
    std::cout << "After: ";
    for (std::vector<int>::iterator it = res1.begin(); it != res1.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << i - 1 << " elements with std::vector<int> : " << durationVector.count() << std::endl;
    std::cout << "Time to process a range of " << i - 1 << " elements with std::deque<int> : " << durationDeque.count() << std::endl; 
    return (0);
}

/*
std::vector<int> VS std::deque<int>
Memory Layout:

    std::vector: Stores elements in a single contiguous block of memory. This allows for very fast random access (constant time O(1)O(1)) because you can directly calculate the memory address of any element using simple pointer arithmetic.
    std::deque: Is implemented as a sequence of non-contiguous blocks of memory. The elements are stored in separate chunks (blocks), and accessing an element requires first finding the correct block and then the element within that block. This indirection makes random access slower compared to vector.

Random Access:

    std::vector allows fast, direct random access to elements via indexing (e.g., vec[i]), which is why algorithms like merge sort, which rely on frequent random access, perform better with vector.
    std::deque, although it also provides random access via indexing (e.g., deque[i]), has to deal with locating the appropriate memory block and then accessing the element inside that block. This extra overhead causes slower random access.
*/