// 6. Zigzag Conversion.cpp : Defines the entry point for the application.
//

#include "header.h"


int main()
{
	std::string str = "PAYPALISHIRING";
	const int ROW = 5;
	Solution2 sol;
	std::string answer = sol.convert(str, ROW);
	
	LOG(answer);
	return 0;
}
