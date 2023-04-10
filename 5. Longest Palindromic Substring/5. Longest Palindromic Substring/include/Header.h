#pragma once
#include <iostream>
#include <algorithm>
#include <string>

template<typename T> void LOG(T x) { std::cout << x << std::endl; }


bool Palindrome(std::string& s) {
	int N = s.size();
	std::string s_tail = "";
	std::string s_head_rev = "";
	// std::string res;
	if (N %2== 0) {
		s_head_rev += s.substr(0, N / 2 );
		std::reverse(s_head_rev.begin(), s_head_rev.end());
		s_tail += s.substr(N / 2, N / 2);
	}
	else {
		s_head_rev += s.substr(0, N / 2 + 1);
		std::reverse(s_head_rev.begin(), s_head_rev.end());
		s_tail += s.substr(N / 2, N / 2 + 1);

	}
	return (s_tail == s_head_rev);
	

}

class Solution1 {
public:
	std::string longestPalindrome(std::string s) {
		std::string ans = "";
		for (int i = s.size(); i > 0; i--) {
			for (int j = 0; j <= s.size()-i;j++) {
				std::string sub = s.substr(j, i);
				if (Palindrome(sub)) return sub;
		}
	}
// 0 1 2 3 4 5 
		
		

		return "kiss me";
	}
	
};

class solution2 {
	class Solution {
	public:
		std::string longestPalindrome(std::string s) {
			int n = s.size();

			if (n == 1) { return s; }

			int longestSubstringLength = 1, longestSubstringLengthStartIndex = 0, start, mid = 0, end;

			while (mid + (longestSubstringLength / 2) < n) {
				start = mid;
				end = mid;

				while (s[mid] == s[end + 1]) {
					++end;
				}

				mid = end + 1;
				while (start > 0 && end + 1 < n && s[start - 1] == s[end + 1]) {
					--start;
					++end;
				}
				if (end - start + 1 > longestSubstringLength) {
					longestSubstringLength = end - start + 1;
					longestSubstringLengthStartIndex = start;
				}
			}

			return s.substr(longestSubstringLengthStartIndex, longestSubstringLength);
		}
	};
};