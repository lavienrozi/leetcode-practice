#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

template<typename T> void LOG(T x) { std::cout << x << std::endl; } 



class Solution {
public:
	int confusingNumberII(int n) {
		// LOG("testing...");
		std::unordered_map <int, int> confusingMap{ {0,0},{1,1},{6,9},{8,8},{9,6} };
		// std::vector<int> invalidvect{ 2, 3, 4, 5, 7 };
		// int num = n;
		int confusingNum = 0; // the result to return
		
		if (n == 0 ) confusingNum = 0;
		else {
			for (int i=1; i<=n; i++) {
				int afterconfusion = 0; // the int after mapping
				int flag = 0; // label this number potentially will confuse you 
				int num = i;
				// std::cout << "iteration: " << i<<"  ";
				while (num > 0) {
					int remainder =  num % 10;
					num /= 10;
					// std::vector<int>::iterator iter = std::find(invalidvect.begin(), invalidvect.end(), remainder);
					if (remainder == 2 || remainder == 3 || remainder == 4 || remainder == 5 || remainder == 7) {
						flag = 0;
						break;
					}
					else if (confusingMap.find(remainder) != confusingMap.end()) {
						flag = 1;
						remainder = confusingMap.find(remainder)->second;
						afterconfusion = afterconfusion * 10 + remainder;
					}
					//if (afterconfusion != i) confusingNum++;
				}
				if (flag == 1 && afterconfusion != i) {
					//LOG(afterconfusion);
					confusingNum++;
				}
			}
		}

		LOG(confusingNum);
		return confusingNum;
	}

}; 


class Solution2 {
public:

	// converts decimal number to base 5 number
	std::string decimal_to_base5(int n)
	{
		std::string ans = "";
		while (n)
		{
			ans += n % 5 + '0';
			n /= 5;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}

	// This converts base 5 number(digits: 0,1,2,3,4) to digits(0,1,6,8,9) respectively
	int base5_to_mybase(std::string s)
	{
		std::string ans = "";

		for (int i = 0; i < s.length(); i++)
		{
			char ch = s[i];

			switch (ch)
			{
			case '0':
				ans.push_back('0');
				break;
			case '1':
				ans.push_back('1');
				break;
			case '2':
				ans.push_back('6');
				break;
			case '3':
				ans.push_back('8');
				break;
			case '4':
				ans.push_back('9');
				break;
			}
		}

		return stoi(ans);
	}


	// This function checks if number n is confusing number or not
	bool is_confusing(int n)
	{
		std::string s = std::to_string(n);
		std::string s2 = s;
		reverse(s2.begin(), s2.end());
		std::string ans;

		for (int i = 0; i < s2.length(); i++)
		{
			char ch = s2[i];
			switch (ch)
			{
			case '0':
				ans.push_back('0');
				break;
			case '1':
				ans.push_back('1');
				break;
			case '6':
				ans.push_back('9');
				break;
			case '8':
				ans.push_back('8');
				break;
			case '9':
				ans.push_back('6');
				break;
			}
		}
		int n2 = stoi(ans);
		return n != n2;
	}


	int confusingNumberII(int n) {

		int i = 1;
		int count = 0;
		while (true)
		{
			int j = base5_to_mybase(decimal_to_base5(i));
			if (j > n) break;
			if (is_confusing(j)) count++;
			i++;
		}
		return count;

	}
};