class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l,r = 0, len(nums) - 1

        while l <= r:
            half = (l + r) // 2
            if target > nums[half]:
                l = half + 1
            elif target < nums[half]:
                r = half - 1
            else:
                return half
        else:
           return l