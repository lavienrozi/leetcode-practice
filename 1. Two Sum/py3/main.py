from solution import Solution

sol = Solution()


def main():
    test_cases = [
        ([2, 7, 11, 15], 9, [0, 1]),
        ([3, 2, 4], 6, [1, 2]),
        ([3, 3], 6, [0, 1]),
    ]

    # Run the test cases and check if the output is as expected
    for nums, target, expected_result in test_cases:
        result = sol.twoSum(nums, target)
        if result == expected_result:
            print(f"Test case {nums} with target {target} PASSED")
        else:
            print(f"Test case {nums} with target {target} FAILED. Expected {expected_result}, but got {result}")

if __name__ == "__main__":
    main()