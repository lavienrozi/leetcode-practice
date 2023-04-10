// 1055. Shortest Way to Form String.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
#include <algorithm>

// TODO: Reference additional headers your program requires here.


class Solution1 {
public:
    int shortestWay(std::string source, std::string target) {

        int last_index = 0;
        int way = 1;
        for (int i = 0; i < target.size(); i++) {
            if (last_index > source.size() - 1) {
                last_index = 0;
                way += 1;
            }
            char cc[] = { target[i], '\0' };
            int curr_src_index = source.find(cc, last_index);
            if (curr_src_index == -1) {
                last_index = source.find(cc);
                if (last_index == -1) return -1;
                else {
                    last_index += 1;
                    way += 1;
                }

            }

            else last_index = curr_src_index + 1;

        }
        return way;
    }
};


class Solution2 {
public:
    int shortestWay(std::string source, std::string target) {
        std::unordered_map<char, std::vector<int>>s;
        int n = source.size(), m = target.size(), j = 0, cnt = 1;
        for (int i = 0; i < n; i++) {
            s[source[i]].push_back(i);
        }

        int ind, last = -1;
        char l;
        while (j < m) {
            l = target[j];
            if (!s.count(l)) return -1;
            ind = (std::upper_bound(s[l].begin(), s[l].end(), last) - s[l].begin());
            if (ind == s[l].size() || s[l][ind] < last) {
                last = -1; cnt++;
            }
            else {
                last = s[l][ind]; j++;
            }
        }
        return cnt;
    }
};


class Solution3 {
public:
    int shortestWay(std::string source, std::string target) {
        int i = 0, j = 0;
        int res = 0;
        bool flag = false;
        while (i < target.size()) {
            if (source[j] == target[i]) {
                i++;
                flag = true;
            }
            j++;
            if (j == source.size()) {
                if (flag == false)
                    return -1;
                res++;
                j = 0;
                flag = false;
            }
        }
        if (i == target.size() && j != 0)
            res++;
        return res;
    }
};
