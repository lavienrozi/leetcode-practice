#pragma once

#include <iostream>
#include <vector>


template <typename T> void LOG(T x) { std::cout << x << std::endl; }


class Solution1 {
public:
    long MOD = 1000000007;
    int util(int s, int e, std::vector<int>& dp)
    {
        if (s >= e)
            return 1;
        if (s == e - 1)
            return 1;
        if (dp[e - s] != -1)
            return dp[e - s];
        int sum = 0;
        for (int i = s + 1; i <= e; i += 2)
        {
            sum = (sum % MOD + (util(s + 1, i - 1, dp) % MOD * util(i + 1, e, dp) % MOD) % MOD) % MOD;
        }
        return dp[e - s] = sum;
    }
    int numberOfWays(int n) {
        std::vector<int> dp(n + 1, -1);
        return util(1, n, dp);
    }
};


unsigned long long binomial(unsigned int n, unsigned int k) {
    std::vector<std::vector<unsigned long long>> dp(n + 1, std::vector<unsigned long long>(k + 1, 0));

    for (unsigned int i = 0; i <= n; ++i) {
        for (unsigned int j = 0; j <= std::min(i, k); ++j) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}


class Solution3 {
public:
    int mul(int a, int b) {
        return (long long)a * b % m;
    }

    int  m = 1'000'000'007;
    int numberOfWays(int numPeople) {


        int n = numPeople / 2;

        std::vector<int>inverse(n + 2);
        inverse[1] = 1;
        for (int i = 2; i < n + 2; i++) {
            int k = m / i;
            int r = m % i;
            inverse[i] = m - mul(k, inverse[r]);
        }
        int result = 1;
        for (int i = 0; i < n; i++) {
            result = mul(mul(2 * (2 * i + 1), inverse[i + 2]), result);
        }

        return result;

    }
};
