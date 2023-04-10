// 67. Add Binary.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>

template<typename T> void LOG(T x) { std::cout << x << std::endl; }
// create a int to binary string 
std::string intTobinary(int num) {
	std::string bin_string;
	if (num == 0)
		return  "0" ;
	int flag = 0;
	for (int i = 31; i >= 0; i--) {
		int bit_mask = 1 << i;
		if (bit_mask & num) {
			bin_string.append("1");
			flag = 1;
		}
		else if (flag>0) {
			bin_string.append("0");
		}

	}
	return bin_string;
}
// create the binary string to int 
int stringToint(std::string string_bin) {
	int result = 0;
	int size_s = string_bin.size();
	for (int i = 0; i < size_s; i++) {
		char temp = string_bin[i] - '0';
		int powered = 1 << (size_s - i - 1);
		auto added = temp * powered;
		result = result + added;
	}
	return result;

}

class Solution1 {
public:
	std::string addBinary(std::string a, std::string b) {
		return (intTobinary((stringToint(a) + stringToint(b))));

	}
};

///

struct strAndcarr {
	std::string str;
	int carr;
};


strAndcarr binarySum(std::string a, std::string b) {
	// size(a) > size(b)
	// int size_a = a.size();
	int size_b = b.size();
	int carry = 0;
	std::string result(size_b,' ');
	for (int i = size_b - 1; i >= 0; i--) {
		int bit_a = a[i] - '0';
		int bit_b = b[i] - '0';
		int result_int = bit_a + bit_b + carry;
		switch (result_int) {
		case 0:
			result[i] = '0';
			carry = 0;
			break;
		case 1:
			result[i] = '1';
			carry = 0;
			break;
		case 2:
			result[i] = '0';
			carry = 1;
			break;
		case 3:
			result[i] = '1';
			carry = 1;
			break;
		}
	}
	strAndcarr pair;
	pair.str = result;
	pair.carr = carry;
	return pair;
}

class Solution2 {
public:
	std::string addBinary(std::string& s1, std::string& s2) {
		std::string a = s1;
		std::string b = s2;

		if (a.size() < b.size()) std::swap(a, b);
		std::string equallizer((a.size() - b.size()), '0');
		std::string b_eq = equallizer + b;

		strAndcarr pair = binarySum(a, b_eq);
		if (pair.carr == 1) {
			return ("1" + pair.str);
		}
		else {
			return pair.str;
		}
	}
};

class Solution3 {
public:
	std::string addBinary(std::string a, std::string b) {
		int pos_a = a.size() - 1;
		int pos_b = b.size() - 1;
		int carry = 0;
		std::string ans = "";
		while (pos_a >= 0 || pos_b >= 0 || carry)
		{
			if (pos_a >= 0)
			{
				carry += (a[pos_a] - '0');
				pos_a--;
			}
			if (pos_b >= 0)
			{
				carry += (b[pos_b] - '0');
				pos_b--;
			}
			ans += (carry % 2 + '0');
			carry /= 2;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

// TODO: Reference additional headers your program requires here.
