// 4. Median of Two Sorted Arrays.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

template<typename T> void LOG(T x) { std::cout << x << std::endl; }

class Solution1 {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::vector<int> merged_vec = nums1;
		merged_vec.insert(merged_vec.end(), nums2.begin(), nums2.end());
		std::sort(merged_vec.begin(), merged_vec.end());
		int midpoint = merged_vec.size() / 2;
		double median_num;
		if (merged_vec.size() % 2 == 1) {
			median_num = static_cast<double>(merged_vec[midpoint]);
		}
		else {
			median_num = ((static_cast<double>(merged_vec[midpoint - 1]) + static_cast<double>(merged_vec[midpoint])) / 2);
		}
		return median_num;


	}
};


// solution 2
class Solution2 {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		int n = (n1 + n2 + 1) / 2; // n is the size of partition that we need to create.
		// First handle the case when one of the vectors is empty
		if (n2 == 0) {
			if (n1 % 2 == 1)
				return nums1[n1 / 2];
			return (1.0 * nums1[n1 / 2 - 1] + nums1[n1 / 2]) / 2;
		}
		if (n1 == 0) {
			if (n2 % 2 == 1)
				return nums2[n2 / 2];
			return (1.0 * nums2[n2 / 2 - 1] + nums2[n2 / 2]) / 2;
		}
		//Binary search on the number of elements we take from 1st vector-nums1 
		int low = 0, high = n1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (mid > n) {
				high = mid - 1;
				continue;
			}
			int cut1 = INT_MIN, cut3 = INT_MAX;
			if (mid != 0)
				cut1 = nums1[mid - 1];
			if (mid != n1)
				cut3 = nums1[mid];

			int cut2 = INT_MIN, cut4 = INT_MAX;
			// Think about this- For a valid partitioning, we need cut1<=cut4 and cut2<=
			int mid2 = n - mid;
			if (mid2 > n2) {
				low = mid + 1;
				continue;
			}
			if (mid2 != n2) {
				cut4 = nums2[mid2];
			}
			if (mid2 != 0)
				cut2 = nums2[mid2 - 1];

			if (cut1 <= cut4 && cut2 <= cut3) {
				if ((n1 + n2) % 2 == 0) {
					return (1.0 * std::max(cut1, cut2) + std::min(cut3, cut4)) / 2;
				}
				return std::max(cut1, cut2);
			}

			if (cut1 > cut4) {
				high = mid - 1;
			}
			else
				low = mid + 1;

		}
		return INT_MIN;
	}
};
