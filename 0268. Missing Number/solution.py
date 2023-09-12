class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        summation = (len(nums) * (len(nums) + 1))/2
        sumnums = sum(nums)

        return summation - sumnums