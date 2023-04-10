#pragma once

#include <iostream>
#include <vector>
#include <set>

template<typename T>
void LOG(T x) { std::cout << x ; }


// credit to ritvic-agg in leetcode
// keywords: recursion, backtrack and std::set<>
void findSubsequences(std::vector<int>& nums, std::vector<int>& subsequence, std::set<std::vector<int>>& result, int size, int index) {
    if (size >= 2) {
    // push the solution into the result 
        result.insert(subsequence);
        // std::cout << "inserted" << std::endl;
    }

    // Iterate through the remaining integers in the input vector
    for (int i = index; i < nums.size(); i++) {
        // std::cout << "index of the vector: " << i << std::endl;
        if (subsequence.size() == 0 || nums[i] >= subsequence[subsequence.size() - 1]) {
            subsequence.push_back(nums[i]);
            findSubsequences(nums, subsequence, result, size + 1, i + 1);
            subsequence.pop_back(); // pop the last element that finished the resursion
        }
    }
}
