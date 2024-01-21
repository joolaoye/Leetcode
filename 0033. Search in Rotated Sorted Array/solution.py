class Solution(object):
    def search(self, nums, target,l=None,r=None):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if l is None: l = 0
        if r is None: r = len(nums) - 1
        if l > r: return -1

        mid = (l + r) // 2

        if nums[mid] == target:
            return mid

        left =  self.search(nums,target,l,mid -1)
        right = self.search(nums,target,mid+1,r)

        return max(left, right)
    