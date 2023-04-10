// 443. String Compression.cpp : Defines the entry point for the application.
//

#include "Header.h"

using namespace std;

int main()
{
	std::vector<char> test_case_1 = { 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
	Solution1 sol;
	int result = sol.compress(test_case_1);
	std::cout << result;




	// cout << "Hello CMake." << endl;
	return 0;
}
