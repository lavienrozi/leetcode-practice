from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # nSet = set()
        dict = {}
        for n in nums: 
            if n in dict:
                return True
            else:
                dict[n] = 1
        return False
    
def main():
    # Create an instance of the Solution class
    sol = Solution()

    # Define some test cases
    test_cases = [
        ([1, 2, 3, 4], False),
        ([1, 2, 3, 1], True),
        ([1, 1, 1, 3, 3, 4, 3, 2, 4, 2], True)
    ]
    
    for nums, expected_result in test_cases:
        result = sol.containsDuplicate(nums)
        if result == expected_result:
            print(f"Test case {nums} PASSED")
        else:
            print(f"Test case {nums} FAILED. Expected {expected_result}, but got {result}")

if __name__ == "__main__":
    main()
        