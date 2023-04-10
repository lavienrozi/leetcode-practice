// 280. Wiggle Sort.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

// TODO: Reference additional headers your program requires here.
template<typename T> void LOG(T x) { std::cout << x << std::endl; }
class Solution1 {
public:
    void wiggleSort(std::vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; i++) {
            if ((i % 2 == 0) && (nums[i] > nums[i + 1])) {
                std::swap(nums[i],nums[i+1]);
            }
            else if ((i % 2 == 1) && (nums[i] < nums[i + 1])) {
                std::swap(nums[i], nums[i + 1]);
            }
        }
    
        for (auto& number : nums) {
            LOG(number);
        }
    }
};

class Solution2 {
public:
    void wiggleSort(std::vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if ((i % 2 == 0 && nums[i] > nums[i + 1]) || (i % 2 == 1 && nums[i] < nums[i + 1])) swap(nums[i], nums[i + 1]);
        }
    }
};
