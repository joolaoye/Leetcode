# Kadene's Algorithm
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxsum = float("-inf")
        cur = float("-inf")

        for num in nums:
            cur = max(cur + num, num)
            maxsum = max(maxsum, cur)

        return maxsum