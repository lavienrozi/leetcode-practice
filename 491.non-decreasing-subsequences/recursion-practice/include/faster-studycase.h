#pragma once
#include <vector>
#include <functional>

class Solution {
public:
    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> t;
        std::function<void(int)> dfs = [&](int i) {
            t.push_back(nums[i]);
            if (t.size() > 1)
                ans.push_back(t);
            for (int j = i + 1; j < nums.size(); ++j) {
                bool flag = true;
                for (int k = i + 1; k < j; ++k)
                    if (nums[k] == nums[j]) {
                        flag = false;
                        break;
                    }
                if (flag && nums[j] >= nums[i]) dfs(j);
            }
            t.pop_back();
        };
        for (int i = 0; i < nums.size() - 1; ++i) {
            bool flag = true;
            for (int j = 0; j < i; ++j)
                if (nums[i] == nums[j]) {
                    flag = false;
                    break;
                }
            if (flag) dfs(i);
        }
        return ans;
    }
};
