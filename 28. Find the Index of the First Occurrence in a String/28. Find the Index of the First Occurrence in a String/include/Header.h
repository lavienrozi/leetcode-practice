#pragma once
#include <string>

class Solution1 {
public:
    int strStr(std::string haystack, std::string needle) {
        return haystack.find(needle);
    }
};


class Solution2 {
public:
    int strStr(std::string haystack, std::string needle) {
        int n_size = needle.size();
        int h_size = haystack.size();
        // std::string h_slice = "";
        if (h_size < n_size) return -1;
        for (int i = 0; i < h_size; i++) {
            if (h_size - i < n_size) return -1;
            if (haystack[i] == needle[0]) {
                for (int j = 0; j < n_size; j++) {
                    // been suggested:
                    if (haystack[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) + j] != needle[j]) break;
                    else if (j == n_size - 1) return i;
                }
            }
        }
        return -1;

    }
};
