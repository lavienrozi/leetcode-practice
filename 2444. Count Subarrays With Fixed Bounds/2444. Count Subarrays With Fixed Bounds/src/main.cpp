#include "Header.h"

int main() {
	LOG("kiss me!");

	std::vector<int> testcase_1 = { 1,3,5,2,7,5 };
	std::vector<int> testcase_2 = { 1,3,2,2,1,3,2,2 };
	// auto index_5 = std::find(testcase_1.begin(), testcase_1.end(), 5);
	// LOG(*index_5);
	Solution1 sol;
	LOG(sol.countSubarrays(testcase_2, 1, 3));

	return 0;
}