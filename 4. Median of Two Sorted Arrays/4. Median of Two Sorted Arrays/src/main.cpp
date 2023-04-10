// 4. Median of Two Sorted Arrays.cpp : Defines the entry point for the application.
//

#include "header.h"


int main()
{
	Solution2 sol;
	std::vector<int> vec1 = { 1,2,3,4 };
	std::vector<int> vec2 = { 7,8,9 };
	double count = sol.findMedianSortedArrays(vec1,vec2);
	LOG(count);
	return 0;
}
