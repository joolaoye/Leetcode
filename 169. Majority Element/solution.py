# Boyer-Mayor Algorithm
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        curr = nums[0]
        count = 1

        for i in range(1, len(nums)):
            if curr == nums[i]: count += 1
            elif count < 1 : 
                count = 1
                curr = nums[i]
            else:
                count -= 1
        return curr