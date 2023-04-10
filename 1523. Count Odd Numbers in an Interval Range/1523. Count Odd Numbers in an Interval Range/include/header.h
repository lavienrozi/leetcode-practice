// 1523. Count Odd Numbers in an Interval Range.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

class Solution1 {
public:
    int countOdds(int& low, int& high) {
        if (low > high) return -1;
        int low_lim = low;
        int N = 0;
        while (low_lim <= high) {
            if (low_lim % 2 != 0) N++; // need to use '!=' other than '=='
            low_lim++;
        }
        return N;
    }
};

class Solution2 {
public:
    int countOdds(int l, int h) {
        return ((h + 1) / 2) - (l / 2);
    }
};

