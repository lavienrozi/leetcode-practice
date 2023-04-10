#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

template<typename T> void LOG(T x) {
	std::cout << x << std::endl;
}

void subarray_counter(std::vector<int>& nums_og, std::vector<int>::iterator it_min, std::vector<int>::iterator it_max, long long& counter) {
	std::vector<int> subvec;
	int index_min = std::distance(nums_og.begin(), it_min);
	int index_max = std::distance(nums_og.begin(), it_max);
	int elemN = std::distance(nums_og.begin(), it_max) - std::distance(nums_og.begin(), it_min) + 1;
	while (it_min != it_max + 1) {
		if (*it_min > *it_max) break;
		subvec.push_back(nums_og[std::distance(nums_og.begin(), it_min)]);
		it_min++;
	}
	counter++;
	std::cout << "[ ";
	for (auto& ele : subvec) std::cout<<ele<<' ';
	std::cout << ']' << std::endl;
	
	
}


class Solution1 {
public:
	long long countSubarrays(std::vector<int>& nums, int minK, int maxK) {
		auto iter_min = std::find(nums.begin(), nums.end(), minK);
		auto iter_max = std::find(nums.begin(), nums.end(), maxK);
		long long counter = 0;
		while (iter_min != nums.end()) {

			while (iter_max != nums.end()) {
				subarray_counter(nums, iter_min, iter_max, counter);
				iter_max = std::find(++iter_max, nums.end(), maxK);

			}

			iter_min = std::find(++iter_min, nums.end(), minK);
			iter_max = std::find(iter_min, nums.end(), maxK);
		}
		

		return counter;

	}
};

class Solution2 {
public:
	long long countSubarrays(std::vector<int>& nums, int minK, int maxK) {
		// initialize some variables
		int n = nums.size();
		int leftBound = -1;
		int lastMin = -1, lastMax = -1;
		long long count = 0;

		for (int i = 0; i < n; i++) {
			// check if nums[i] is within the range [minK, maxK]
			if (nums[i] >= minK && nums[i] <= maxK) {
				// if nums[i] is equal to minK, update lastMin to the current index i
				lastMin = (nums[i] == minK) ? i : lastMin;
				// if nums[i] is equal to maxK, update lastMax to the current index i
				lastMax = (nums[i] == maxK) ? i : lastMax;
				// update the count by the number of valid subarrays between leftBound and the 
				// smaller of lastMin and lastMax
				count += std::max(0, std::min(lastMin, lastMax) - leftBound);
			}
			else {
				// if nums[i] is not within the range [minK, maxK], update leftBound to i
				leftBound = i;
				// reset lastMin and lastMax to -1
				lastMin = -1;
				lastMax = -1;
			}
		}

		// return the final count of valid subarrays
		return count;
	}
};

