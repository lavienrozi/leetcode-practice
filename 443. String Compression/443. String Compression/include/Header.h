// 443. String Compression.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>

class Solution1 {
public:
    int compress(std::vector<char>& chars) {
        std::vector<char> temp, ans;
        int count = 0;
        std::string count_str;

        for (int i = 0; i < chars.size(); i++) {
            if (i == 0 || chars[i] == chars[i - 1]) {
                temp.push_back(chars[i]);
                count++;
            }
            else {
                if (!temp.empty()) ans.push_back(temp[0]);
                count_str = std::to_string(count);
                if (count_str != "1") {
                    for (char& c : count_str) ans.push_back(c);
                }
                temp.clear();
                count = 1;
                temp.push_back(chars[i]);
            }

        }
        if (!temp.empty()) ans.push_back(temp[0]);
        count_str = std::to_string(count);
        if (count_str != "1") {
            for (char& c : count_str) ans.push_back(c);
        }
        return ans.size();
    }
};


class Solution2 {
public:
    int compress(std::vector<char>& chars) {
        if (chars.empty()) return 0;
        char curr = chars[0];
        int count = 1;
        string s;
        for (int i = 1; i <= chars.size(); i++) {
            if (i < chars.size() && chars[i] == curr) {
                count++;
            }
            else {
                s.push_back(curr);
                if (count > 1) {
                    string str = to_string(count);
                    for (char c : str) {
                        s.push_back(c);
                    }
                }
                curr = i < chars.size() ? chars[i] : 0;
                count = 1;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            chars[i] = s[i];
        }
        return s.size();
    }
};

class Solution3 {
public:
    int compress(std::vector<char>& chars) {
        int n = chars.size();
        if (n == 1) {
            return 1;
        }

        int i = 0, j = 0;
        while (i < n) {
            int count = 1;
            while (i < n - 1 && chars[i] == chars[i + 1]) {
                count++;
                i++;
            }

            chars[j++] = chars[i++];
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[j++] = c;
                }
            }
        }

        return j;
    }
};
// TODO: Reference additional headers your program requires here.
