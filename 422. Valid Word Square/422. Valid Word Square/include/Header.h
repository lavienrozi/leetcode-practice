// 422. Valid Word Square.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>

class Solution1 {
public:
    bool validWordSquare(std::vector<string>& words) {
        for (int j = 0; j < words.size(); j++) {
            string word_row = "";
            if (words.size() < words[j].size()) return false;
            for (int i = 0; i < words[j].size(); i++) {
                // word_row.push_back(words[i][j]);
                word_row += words[i][j];
                // cout<<words[i][j];
            }

            if (words[j] != word_row) return false;
        }
        return true;
    }
};

// TODO: Reference additional headers your program requires here.
