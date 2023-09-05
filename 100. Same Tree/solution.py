# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Recursive Solution
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if not(p or q) : return True

        if (not p and q) or (p and not q) : return False
        
        if p.val != q.val: return False

        left = self.isSameTree(p.left, q.left)
        right = self.isSameTree(p.right, q.right)

        return left and right
    
# Sub-Optimal Iterative
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        queuep = [p]
        exploredp = []

        queueq = [q]
        exploredq = []

        while queuep:
            current = queuep.pop(0)

            if current:
                exploredp.append(current.val)

                queuep.append(current.left)

                queuep.append(current.right)

            else:
                exploredp.append(current)


        while queueq:
            current = queueq.pop(0)
            
            if current:
                exploredq.append(current.val)

                queueq.append(current.left)

                queueq.append(current.right)

            else:
                exploredq.append(current)

        return exploredp == exploredq