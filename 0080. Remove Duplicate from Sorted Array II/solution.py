class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 2:
            return len(nums)

        l = 2

        for i in range(2, len(nums)):
            if nums[i] != nums[l-2]:
                nums[l] = nums[i]
                l += 1

        return l
    