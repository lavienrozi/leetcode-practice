// 67. Add Binary.cpp : Defines the entry point for the application.
//

#include "header.h"


int main()
{
	int numTest = 80;
	std::string a = "1010";
	std::string b = "1011";
	int int1 = stringToint(a);
	int int2 = stringToint(b);
	// Solution1 sol;
	// LOG(sol.addBinary(a, b));
	Solution2 sol;
	LOG(sol.addBinary(a, b));

	return 0;
}
