#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution1 {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); i++) {
            if (ump.find(nums[i]) != ump.end())
                return true;
            ump[nums[i]] = i;
        }
        return false;


    }
};

class Solution3 {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std:: sort(nums.begin(), nums.end());

        for (int i = 1; i <= nums.size() - 1; i++) {
            if (nums[i - 1] == nums[i]) {
                return true;
            }
        }
        return false;
    }
};
