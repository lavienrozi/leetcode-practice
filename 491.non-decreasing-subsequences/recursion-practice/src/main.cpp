#include "recursion.h"

int main() {
	std::vector<int> nums = { 4,9,3,6,7,7 };
	std::vector<int> subsequence;

	std::set<std::vector<int>> resultSet;
	
	findSubsequences(nums, subsequence, resultSet, 0, 0) ;

	
	return 0;

}
