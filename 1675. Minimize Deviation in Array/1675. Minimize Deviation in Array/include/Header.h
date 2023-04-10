// 1675. Minimize Deviation in Array.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

// TODO: Reference additional headers your program requires here.

template<typename T> void LOG(T x) { std::cout << x << std::endl; }


class Solution1 {
public:
    int minimumDeviation(std::vector<int>& nums) {
        auto max_it = std::max_element(nums.begin(), nums.end());
        auto max_index = std::distance(nums.begin(), max_it);
        LOG(*max_it);
    }
};
