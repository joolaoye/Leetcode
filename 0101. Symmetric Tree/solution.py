# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Iterative Solution
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None: return False

        def preorderleft(root):
            if root is None: return [None]

            if not (root.left or root.right): return [root.val]

            left = preorderleft(root.left)
            right = preorderleft(root.right)

            return [root.val] + left + right

        def preorderright(root):
            if root is None: return [None]

            if not (root.left or root.right): return [root.val]

            left = preorderright(root.left)
            right = preorderright(root.right)

            return [root.val] + right + left

        left = preorderleft(root.left)
        right = preorderright(root.right)

        print(left, right)

        return left == right


# Recursive solution
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def checksubtrees(nodeA, nodeB):
            if not (nodeA or nodeB): return True

            if not nodeA or not nodeB: return False

            if nodeA.val != nodeB.val: return False

            return checksubtrees(nodeA.left, nodeB.right) and checksubtrees(nodeA.right, nodeB.left)

        
        return checksubtrees(root.left, root.right)