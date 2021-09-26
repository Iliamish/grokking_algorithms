// grokking_algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "1_binary_search.h"
#include "2_quick_sort.h"

int main()
{
    std::vector<int> vec{ 10,20,30,53,1,4,6,8,9,13,54,100 };
    
    quick_sort(vec, 0, vec.size() - 1);

    return 0;
}
