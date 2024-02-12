class Solution(object):
    """ Recursion """
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # base case
        if len(nums) == 1: return [nums[:]]

        res = []

        for _ in range(len(nums)):
            temp = nums.pop(0)

            perms = self.permute(nums)

            for perm in perms:
                perm.append(temp)

            res.extend(perms)
            nums.append(temp)


        return res
            