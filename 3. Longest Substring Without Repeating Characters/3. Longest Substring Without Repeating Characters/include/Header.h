// 3. Longest Substring Without Repeating Characters.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
#include <algorithm>

template<typename T> void LOG(T x) { std::cout << x << std::endl; }

// TODO: Reference additional headers your program requires here.
class Solution1 {
public:
	int lengthOfLongestSubstring(std::string& s) {
		
		int len = 0;
		int conNums = 1;
		std::string mag;

		for (int i = 0; i < s.size(); i++) {
			// int conNums = 1;
			if (i > 0) {
				if (mag.find(s[i]) == std::string::npos) {
					// mag.push_back(s[i]);
					conNums++;
					if (len < conNums) {
						len = conNums;
					
				}

				}
				else {
					int erasedpos = mag.find(s[i]);
					for (int j = erasedpos; j >= 0; j--) {
						mag.erase(j, 1);
					}
					

					// mag.clear();
					// mag.push_back(s[i]);
					conNums = conNums - (erasedpos);
					if (conNums < 1) conNums = 1;
				}
				mag.push_back(s[i]);
				
			}
			else {
				len = 1;
				mag.push_back(s[i]);
			}
		}
	 
			
		LOG(len);
		// for (auto& str : s) {
		//     std::cout << i;
		//     LOG(str);
		//     i++;
		// }
		return len;
	}
};


class Solution2 {
public:
	int lengthOfLongestSubstring(std::string s)
	{
		int map[128] = {}, last_repeat = 0, res = 0;
		for (auto i = 0; i < s.size(); i++) {
			last_repeat = std::max(last_repeat, map[s[i]]);
			res = std::max(res, i + 1 - last_repeat);
			map[s[i]] = i + 1;
		}

		return res;
	}
};
