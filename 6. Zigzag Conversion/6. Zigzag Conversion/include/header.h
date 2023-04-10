// 6. Zigzag Conversion.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
#include <vector>

// TODO: Reference additional headers your program requires here.

template<typename T> void LOG(T x) { std::cout << x << std::endl; }

class Solution1 {
public:

    std::string convert(std::string s, int numRows) {

        if (numRows <= 1) return s;

        std::vector<std::string>v(numRows, "");

        int j = 0, dir = -1;

        for (int i = 0; i < s.length(); i++)
        {

            if (j == numRows - 1 || j == 0) dir *= (-1);

            v[j] += s[i];

            if (dir == 1) j++;

            else j--;
        }

        std::string res;

        for (auto& it : v) res += it;

        return res;

    }
};

// from uzumaki_ichigo

class Solution2 {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;
        std::string ans = "";
        for (int i = 0; i < numRows; i++) {
            int jumps = 2 * (numRows - 1);  //no of jumps to do for reaching the next element of row
            for (int j = i; j < s.length(); j += jumps) {   // increment j always by jumps
                ans += s[j];
                int midJumps = j + jumps - 2 * i;   // jumps for middle rows 
                if (i > 0 && i < numRows - 1 && midJumps < s.length())  // check if middle jumps are in range
                    ans += s[midJumps];
            }
        }
        return ans;
    }
};

// iterate thru zig zag shape 
// from sonal91022
//

lass Solution{
public:
    string convert(string s, int numRows) {
        vector<string>ans(min(numRows, int(s.size())));
        string result = "";
        if (numRows == 1) {
            return s;
        }
        bool down = false;
        int value = 0;
        for (char c : s) {
            ans[value] += c;
            if (value == 0 || value == numRows - 1) {
                down = !down;
            }
            if (down) {
                value += 1;
            }
else {
   value = value - 1;
}
}
for (string row : ans)
 {
     result += row;
 }
 return result;

}
};

// Hardway, inspired by ockhamrazor
// simulate and add each character to the corresponding row
// go down -> reach bottom -> go up -> reach top -> go down ...
class Solution4 {
public:
    string convert(string s, int n) {
        // edge case
        if (n == 1) return s;
        vector<string> rows(n);
        // j is the index to track which rows a character should be added to
        // d is the direction: -1 means go up, 1 means go down
        int j = 0, d = 1;
        for (int i = 0; i < s.size(); i++) {
            // add the current character to corresponding row
            rows[j] += s[i];
            // if it reaches to the last row, we need to go up
            if (j == n - 1) d = -1;
            // if it reaches to the first row, we need to go down
            else if (j == 0) d = 1;
            // move j pointer
            j += d;
        }
        // rows would look like below in the first example
        // ['PAHN', 'APLSIIG', 'YIR']
        // we use `accumulate` to build the final answer (in C++ 20, it takes O(n) only)
        return accumulate(rows.begin(), rows.end(), string{});
    }
};
