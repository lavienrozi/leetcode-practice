---
tags: " #DSA/Array, #DSA/Divide-and-Conquer, #DSA/Dynamic-Programming, #DSA/Recursion, #DSA/Tabulation, #DSA/Memoization"
---
From [archit91](https://leetcode.com/archit91/) [link](https://leetcode.com/problems/maximum-subarray/solutions/1595195/c-python-7-simple-solutions-w-explanation-brute-force-dp-kadane-divide-conquer/?envType=study-plan&id=data-structure-i)

We are given an array `nums` and we need to return the maximum sum of a subarray in `nums`.

---

❌ _**Solution - I (Brute-Force) [TLE]**_

We can start with brute-force by trying out every possible sub-array in `nums` and choosing the one with maximum sum.

**C++**
```cpp
class Solution { 
public: int maxSubArray(vector<int>& nums) { 
	int n = size(nums), ans = INT_MIN; 
		for(int i = 0; i < n; i++) 
			for(int j = i, curSum = 0; j < n ; j++) 
				curSum += nums[j], 
				ans = max(ans, curSum); 
		return ans; 
	} 
};

```
**Python**
```python
class Solution:
    def maxSubArray(self, nums):
        ans = -inf
        for i in range(len(nums)):
            cur_sum = 0
            for j in range(i, len(nums)):
                cur_sum += nums[j]
                ans = max(ans, cur_sum)
        return ans
```

_**Time Complexity :**_ `O(N2)`, where `N` is the number of elements in `nums`. There are `N*(N+1)/2` total sub-arrays and trying out each one takes time of `O(N2)`  
_**Space Complexity :**_ `O(1)`

❌ _**Solution - II (Recursive) [TLE]**_

Another way to consider every subarray and return the one that has maximum sum is using recursive approach. Here we can state the approach as -

-   At each index `i`, we can either pick that element or not pick it.
-   If we pick current element, then all future element must also be picked since our array needs to be contiguous.
-   If we had picked any elements till now, we can either end further recursion at any time by returning sum formed till now or we can choose current element and recurse further. This denotes two choices of either choosing the subarray formed from 1st picked element till now or expanding the subarray by choosing current element respectively.

In the code below, we will use `mustPick` to denote whether we must compulsorily pick current element. When `mustPick` is true, we must either return `0` or pick current element and recurse further. If `pickCur` is false, we have both choices of not picking current element and moving on to next element, or picking the current one.

**C++**

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {    
        return solve(nums, 0, false);
    }
    int solve(vector<int>& A, int i, bool mustPick) {
		// our subarray must contain atleast 1 element. If mustPick is false at end means no element is picked and this is not valid case
        if(i >= size(A)) return mustPick ? 0 : -1e5;       
        if(mustPick)
            return max(0, A[i] + solve(A, i+1, true));                  // either stop here or choose current element and recurse
        return max(solve(A, i+1, false), A[i] + solve(A, i+1, true));   // try both choosing current element or not choosing
    }
};
```

**Python**

```python
class Solution:
    def maxSubArray(self, nums):
        def solve(i, must_pick):
            if i >= len(nums): return 0 if must_pick else -inf
            return max(nums[i] + solve(i+1, True), 0 if must_pick else solve(i+1, False))
        return solve(0, False)
```

_**Time Complexity :**_ `O(N2)`, we are basically considering every subarray sum and choosing maximum of it.  
_**Space Complexity :**_ `O(N)`, for recursive space


✔️ _**Solution - III (Dynamic Programming - Memoization)**_

We can observe a lot of repeated calculations if we draw out the recursive tree for above solution -

```erlang
                                                f(0, False)                       🔽 => repeated calculations
					                          /             \ 
                       		       f(1, False)              f(1, True)
			                      /          \       🔽          \      🔽
			                 f(2, False)      f(2, True)           f(2, True)
							/            \  🔽       \   🔽           \  🔽
						f(3, False)   f(3,True)     f(3, True)           f(3, True)
						/        \            \           \                  \
				      ...        ...          ...         ...                ...
```

These redundant calculations can be eliminated if we store the results for a given state and reuse them later whenever required rather than recalculating them over and over again.

Thus, we can use memoization technique here to make our solution more efficient. Here, we use a `dp` array where `dp[mustPick][i]` denotes the maximum sum subarray starting from `i` and `mustPick` denotes wheter the current element must be picked compulsorily or not.

**C++**

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {    
        vector<vector<int>> dp(2, vector<int>(size(nums), -1));
        return solve(nums, 0, false, dp);
    }
    int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {
        if(i >= size(A)) return mustPick ? 0 : -1e5;
        if(dp[mustPick][i] != -1) return dp[mustPick][i];
        if(mustPick)
            return dp[mustPick][i] = max(0, A[i] + solve(A, i+1, true, dp));
        return dp[mustPick][i] = max(solve(A, i+1, false, dp), A[i] + solve(A, i+1, true, dp));
    }
};
```

**Python**

```python
class Solution:
    def maxSubArray(self, nums):
        @cache
        def solve(i, must_pick):
            if i >= len(nums): return 0 if must_pick else -inf
            return max(nums[i] + solve(i+1, True), 0 if must_pick else solve(i+1, False))
        return solve(0, False)
```

_**Time Complexity :**_ `O(N)`, we are calculating each state of the `dp` just once and memoizing the result. Thus, we are calculating results for `2*N` states and returning them directly in future recursive calls.  
_**Space Complexity :**_ `O(N)`, for recursive space

---

✔️ _**Solution - IV (Dynamic Programming - Tabulation)**_

We can employ similar logic in iterative version as well. Here, we again use `dp` array and use bottom-up approach. Here `dp[1][i]` denotes maximum subarray sum ending at `i` (including `nums[i]`) and `dp[0][i]` denotes maximum subarray sum upto `i` (may or may not include `nums[i]`).

At each index, we update `dp[1][i]` as max between either only choosing current element - `nums[i]` or extending from previous subarray and choosing current element as well - `dp[1][i-1] + nums[i]`  
Similarly, `dp[0][1]` can be updated as max between maximum sum subarray found till last index - `dp[0][i-1]` or max subarray sum found ending at current index `dp[1][i]`.

**C++**

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(size(nums)));
        dp[0][0] = dp[1][0] = nums[0];
        for(int i = 1; i < size(nums); i++) {
            dp[1][i] = max(nums[i], nums[i] + dp[1][i-1]);
            dp[0][i] = max(dp[0][i-1], dp[1][i]);
        }
        return dp[0].back();
    }
};
```

**Python**

```python
class Solution:
    def maxSubArray(self, nums):
        dp = [[0]*len(nums) for i in range(2)]
        dp[0][0], dp[1][0] = nums[0], nums[0]
        for i in range(1, len(nums)):
            dp[1][i] = max(nums[i], nums[i] + dp[1][i-1])
            dp[0][i] = max(dp[0][i-1], dp[1][i])
        return dp[0][-1]
```

We can actually do away with just 1 row as well. We denoted `dp[1][i]` as the maximum subarray sum ending at `i`. We can just store that row and calculate the overall maximum subarray sum at the end by choosing the maximum of all max subarray sum ending at `i`.

**C++**

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        for(int i = 1; i < size(nums); i++) 
            dp[i] = max(nums[i], nums[i] + dp[i-1]);        
        return *max_element(begin(dp), end(dp));
    }
};
```

**Python**

```python
class Solution:
    def maxSubArray(self, nums):
        dp = [*nums]
        for i in range(1, len(nums)):
            dp[i] = max(nums[i], nums[i] + dp[i-1])
        return max(dp)
```

_**Time Complexity :**_ `O(N)`, we are just iterating over the `nums` array once to compute the `dp` array and once more over the `dp` at the end to find maximum subarray sum. Thus overall time complexity is `O(N) + O(N) = O(N)`  
_**Space Complexity :**_ `O(N)`, for maintaining `dp`.

---

✔️ _**Solution - V (Kadane's Algorithm)**_

We can observe that in the previous approach, `dp[i]` only depended on `dp[i-1]`. So do we really need to maintain the whole `dp` array of `N` elements? One might see the last line of previous solution and say that we needed all elements of `dp` at the end to find the maximum sum subarray. But we can simply optimize that by storing the max at each iteration instead of separately calculating it at the end.

Thus, we only need to maintain `curMax` which is the maximum subarray sum ending at `i` and `maxTillNow` which is the maximum sum we have seen till now. And this way of solving this problem is what we popularly know as **Kadane's Algorithm**

**C++**

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0, maxTillNow = INT_MIN;
        for(auto c : nums)
            curMax = max(c, curMax + c),
            maxTillNow = max(maxTillNow, curMax);
        return maxTillNow;
    }
};
```

**Python**

```python
class Solution:
    def maxSubArray(self, nums):
        cur_max, max_till_now = 0, -inf
        for c in nums:
            cur_max = max(c, cur_max + c)
            max_till_now = max(max_till_now, cur_max)
        return max_till_now
```

_**Time Complexity :**_ `O(N)`, for iterating over `nums` once  
_**Space Complexity :**_ `O(1)`, only constant extra space is being used.

_PS:_ I have tried running `Solution - IV` and this solution multiple times and this solution, despite being `O(1)` shows higher memory usage(`28.8 MB` on average vs `28 MB` used by solution - IV) by LC consistently. If anyone can figure out the reason behind this, I will be happy to hear it out :)

---

✔️ _**Solution - VI (Divide & Conquer)**_

We can solve this using divide and conquer strategy. This is the follow-up question asked in this question. This involves modelling the problem by observing that the maximum subarray sum is such that it lies somewhere -

-   entirely in the left-half of array `[L, mid-1]`, OR
-   entirely in the right-half of array `[mid+1, R]`, OR
-   in array consisting of mid element along with some part of left-half and some part of right-half such that these form contiguous subarray - `[L', R'] = [L', mid-1] + [mid] + [mid+1,R']`, where `L' >= L` and `R' <= R`

With the above observation, we can recursively divide the array into sub-problems on the left and right halves and then combine these results on the way back up to find the maximum subarray sum.

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, size(nums)-1);
    }
    int maxSubArray(vector<int>& A, int L, int R){
        if(L > R) return INT_MIN;
        int mid = (L + R) / 2, leftSum = 0, rightSum = 0;
        // leftSum = max subarray sum in [L, mid-1] and starting from mid-1
        for(int i = mid-1, curSum = 0; i >= L; i--)
            curSum += A[i],
            leftSum=max(leftSum, curSum);
        // rightSum = max subarray sum in [mid+1, R] and starting from mid+1
        for(int i = mid+1, curSum = 0; i <= R; i++)
            curSum += A[i],
            rightSum = max(rightSum, curSum);        
		// return max of 3 cases 
        return max({ maxSubArray(A, L, mid-1), maxSubArray(A, mid+1, R), leftSum + A[mid] + rightSum });
    }	
};
```

**Python**

```python
class Solution:
    def maxSubArray(self, nums):
        def maxSubArray(A, L, R):
            if L > R: return -inf
            mid, left_sum, right_sum, cur_sum = (L + R) // 2, 0, 0, 0
            for i in range(mid-1, L-1, -1):
                left_sum = max(left_sum, cur_sum := cur_sum + A[i])
            cur_sum = 0
            for i in range(mid+1, R+1):
                right_sum = max(right_sum, cur_sum := cur_sum + A[i])
            return max(maxSubArray(A, L, mid-1), maxSubArray(A, mid+1, R), left_sum + A[mid] + right_sum)
        return maxSubArray(nums, 0, len(nums)-1)
```

_**Time Complexity :**_ `O(NlogN)`, the recurrence relation can be written as `T(N) = 2T(N/2) + O(N)` since we are recurring for left and right half (`2T(N/2)`) and also calculating maximal subarray including mid element which takes `O(N)` to calculate. Solving this recurrence using master theorem, we can get the time complexity as `O(NlogN)`  
_**Space Complexity :**_ `O(logN)`, required by recursive stack

---

✔️ _**Solution - VII (Optimized Divide & Conquer)**_

We can further optimize the previous solution. The `O(N)` term in the recurrence relation of previous solution was due to computation of max sum subarray involving `nums[mid]` in each recursion.

But we can reduce that term to `O(1)` if we precompute it. This can be done by precomputing two arrays `pre` and `suf` where `pre[i]` will denote maximum sum subarray ending at `i` and `suf[i]` denotes the maximum subarray starting at `i`. `pre` is similar to `dp` array that we computed in dynamic programming solutions and `suf` can be calculated in similar way, just by starting iteration from the end.

**C++**

```cpp
class Solution {
public:
    vector<int> pre, suf;
    int maxSubArray(vector<int>& nums) {
        pre = suf = nums;
        for(int i = 1; i < size(nums); i++)  pre[i] += max(0, pre[i-1]);
        for(int i = size(nums)-2; ~i; i--)   suf[i] += max(0, suf[i+1]);
        return maxSubArray(nums, 0, size(nums)-1);
    }
    int maxSubArray(vector<int>& A, int L, int R){
        if(L == R) return A[L];
        int mid = (L + R) / 2;
        return max({ maxSubArray(A, L, mid), maxSubArray(A, mid+1, R), pre[mid] + suf[mid+1] });
    }	
};
```

**Python**

```python
class Solution:
    def maxSubArray(self, nums):
        pre, suf = [*nums], [*nums]
        for i in range(1, len(nums)):       pre[i] += max(0, pre[i-1])
        for i in range(len(nums)-2,-1,-1):  suf[i] += max(0, suf[i+1])
        def maxSubArray(A, L, R):
            if L == R: return A[L]
            mid = (L + R) // 2
            return max(maxSubArray(A, L, mid), maxSubArray(A, mid+1, R), pre[mid] + suf[mid+1])
        return maxSubArray(nums, 0, len(nums)-1)
```

_**Time Complexity :**_ `O(N)`, the recurrence relation can be written as `T(N) = 2T(N/2) + O(1)` since we are recurring for left and right half (`2T(N/2)`) and calculating maximal subarray including mid element in `O(1)`. Solving this recurrence using master theorem, we can get the time complexity as `O(N)`  
_**Space Complexity :**_ `O(N)`, required by `suf` and `pre`.

This code is an implementation of a divide-and-conquer approach to solving the maximum subarray problem, which aims to find the contiguous subarray within a one-dimensional array that has the largest sum. The given code first computes prefix and suffix sums in the `maxSubArray(vector<int>& nums)` function, and then it recursively calls the overloaded `maxSubArray(vector<int>& A, int L, int R)` function to find the maximum subarray sum.

Let's go through the code execution step by step using the provided test case:

Input: `nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}`

1.  Initialize `pre` and `suf` with `nums`: `pre = {-2, 1, -3, 4, -1, 2, 1, -5, 4}`, `suf = {-2, 1, -3, 4, -1, 2, 1, -5, 4}`
    
2.  Compute prefix sums with positive accumulation: `pre = {-2, 1, -2, 4, 3, 5, 6, 1, 5}`
    
3.  Compute suffix sums with positive accumulation: `suf = {5, 8, 7, 6, 3, 3, 2, 0, 4}`
    
4.  Call `maxSubArray(nums, 0, 8)`, which has the following steps: a. Check if L == R (0 == 8), which is false. b. Calculate mid = (0 + 8) / 2 = 4 c. Call `maxSubArray(nums, 0, 4)`: i. Check if L == R (0 == 4), which is false. ii. Calculate mid = (0 + 4) / 2 = 2 iii. Call `maxSubArray(nums, 0, 2)`: The result is 1 (subarray {1}) iv. Call `maxSubArray(nums, 3, 4)`: The result is 4 (subarray {4}) v. Return max({1, 4, pre[2] + suf[3]}) = max({1, 4, -2 + 6}) = 4 d. Call `maxSubArray(nums, 5, 8)`: i. Check if L == R (5 == 8), which is false. ii. Calculate mid = (5 + 8) / 2 = 6 iii. Call `maxSubArray(nums, 5, 6)`: The result is 3 (subarray {2, 1}) iv. Call `maxSubArray(nums, 7, 8)`: The result is 4 (subarray {4}) v. Return max({3, 4, pre[6] + suf[7]}) = max({3, 4, 6 + 0}) = 6 e. Return max({4, 6, pre[4] + suf[5]}) = max({4, 6, 3 + 3}) = 6
    

The final output is 6, which corresponds to the maximum subarray sum found in the input array `nums`. The maximum subarray is {4, -1, 2, 1}.

---

💡 **Note:**

-   The above divide and conquer solution works in `O(N)` but is **once you have calculated `pre` and `suf`, does it even make sense to go into divide and conquer approach?** I dont think divide and conquer approach after calculating `pre` & `suf`is useful, unless you Really want to solve it using **❝Divde and Conquer❞ only**. You can instead do the following (which is similar to dp)-
    
    ```cpp
    class Solution {
    public:
    	int maxSubArray(vector<int>& nums) {
    		vector<int> pre = nums;
    		for(int i = 1; i < size(nums); i++) pre[i] += max(0, pre[i-1]);
    		return *max_element(begin(pre), end(pre));
    	}
    };
    ```
