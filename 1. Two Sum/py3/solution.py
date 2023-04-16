from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        numsDict = dict()
        
        for i, num in enumerate(nums):
            val = target - num
            if val in numsDict:
                pairedIndex = numsDict[val]
                return [pairedIndex,i]
            else:
                numsDict[num] = i