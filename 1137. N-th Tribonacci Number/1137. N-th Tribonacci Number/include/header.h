// 1137. N-th Tribonacci Number.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.

class Solution1 {
public:

    int tribonacci(int n) {
        if (n < 3) return n == 0 ? 0 : 1; //interesting watch 0 and 1
        int* tri = new int[n + 1];
        tri[0] = 0;
        tri[1] = 1;
        tri[2] = 1;
        for (int i = 3; i < n + 1; i++) {
            tri[i] = tri[i - 1] + tri[i - 2] + tri[i - 3];
        }
        return tri[n];
    }
};

// solution 2-4 from Xahoor72
// solution 2 for recursion 
// Recusrion with Memiozation

#include <cstring>

class Solution2  {
public:
    int dp[38];
    int fib1(int n) {
        if (n == 0)return dp[n] = 0;
        if (n == 1 or n == 2)return dp[n] = 1;

        if (dp[n] != -1)return dp[n];

        return dp[n] = fib1(n - 1) + fib1(n - 2) + fib1(n - 3);
    }
    int tribonacci(int n) {
        std::memset(dp, -1, sizeof(dp)); // fill the memory with -1
        return fib1(n);
    }
};

// solution 3 DP with O(1) Space(Beats 100 %) 
// base of 3, keep refreshing the dp[0] dp[1] dp[2] values

class Solution3 {
public:
    int tribonacci(int n) {
        int dp[] = { 0,1,1 };
        for (int i = 3; i <= n; i++) {
            dp[i % 3] = dp[0] + dp[1] + dp[2];
        }
        return dp[n % 3];
    }
};

// solution4 Iterative Approach (Beats 100%)

class Solution4 {
public:
    int tribonacci(int n) {
        if (n < 2)return n;
        int t1 = 1, t2 = 1, t0 = 0, t3;
        for (int i = 3; i <= n; i++) {
            t3 = (t0 + t2 + t1);
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }
        return t3;
    }
};
