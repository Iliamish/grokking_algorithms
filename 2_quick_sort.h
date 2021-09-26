#pragma once
#include "base.h"

template <typename T>
std::size_t partitioner(std::vector<T>& vec, std::size_t low, std::size_t high) {
	std::size_t i = low;

    T pivot = vec[high];

    for (std::size_t j = low; j < high; j++) {
        if (vec[j] < pivot) {
            std::swap(vec[i], vec[j]);
            i++;
        }
    }

    std::swap(vec[i], vec[high]);

    return i;
}

template <typename T>
void quick_sort(std::vector<T>& vec, std::size_t low, std::size_t high) {
    if (low < high) {
        std::size_t pivot = partitioner(vec, low, high);

        quick_sort(vec, low, pivot - 1);
        quick_sort(vec, pivot + 1, high);
    }
}