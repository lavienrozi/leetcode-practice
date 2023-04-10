// 1055. Shortest Way to Form String.cpp : Defines the entry point for the application.
//

#include "Header.h"

int main()
{
	std::string s = "xzyxz";
	Solution2 sol;
	int res = sol.shortestWay("xyz", s);
	std::cout << res << std::endl;
	return 0;
}
