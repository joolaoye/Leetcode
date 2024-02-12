class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if not nums:
            return
            
        l,r = 0, len(nums) - 1

        mid = (l + r)//2

        head = TreeNode(nums[mid])
        head.left = self.sortedArrayToBST(nums[:mid])
        head.right = self.sortedArrayToBST(nums[mid+1:])
        
        return head
        