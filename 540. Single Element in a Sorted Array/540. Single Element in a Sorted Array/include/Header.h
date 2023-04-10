#pragma once

#include <iostream>
#include <vector>

class Solution1 {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        //if ()
        for (int i = 0; i < nums.size() - 2; i += 2) {
            if (nums.size() < 2) return nums[0];
            else if (nums[i] != nums[i + 1]) return nums[i];
        }
        return nums[nums.size() - 1];

    }
};


class Solution2{


};
