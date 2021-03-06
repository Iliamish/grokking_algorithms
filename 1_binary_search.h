#pragma once
#include "base.h"

template <typename T, typename Compare = std::less<T>>
auto binary_search(const std::vector<T>& vector, const T& item, Compare comp = Compare()) {
	auto low = vector.begin();
	auto high = vector.end();
	auto mid = low + (high - low) / 2;

	while (low < high) {
		if (*mid == item) {
			return mid;
		} else {
			if (comp(*mid, item)) {
				low = mid+1;
			} else {
				high = mid-1;
			}
		}
		mid = low + (high - low) / 2;
	}
	return vector.end();
}