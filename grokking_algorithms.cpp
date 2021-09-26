// grokking_algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "1_binary_search.h"
#include "2_quick_sort.h"
#include "7_Dijkstra.h"

int main()
{
    //std::vector<int> vec{ 10,20,30,53,1,4,6,8,9,13,54,100 };
    //
    //quick_sort(vec, 0, vec.size() - 1);

    GraphNode* first = new GraphNode(1, 0);
    GraphNode* second = new GraphNode(2, -1);
    GraphNode* third = new GraphNode(3, -1);
    GraphNode* fourth = new GraphNode(4, -1);

    first->children = std::vector<std::pair<GraphNode*, std::size_t>>{ {second, 6}, { third, 2 } };
    third->children = std::vector<std::pair<GraphNode*, std::size_t>>{ {second, 3}, { fourth, 5 } };
    second->children = std::vector<std::pair<GraphNode*, std::size_t>>{ { fourth, 1 } };

    findOptimalPath(first, fourth);
    return 0;
}
