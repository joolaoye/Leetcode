# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


# Hashset Solution
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        tail = head
        hashset = set()

        while tail and tail.next:
            hashset.add(tail)
            if tail in hashset:
                return True
            tail = tail.next
        
        return False

# Floyd-Cycle Detection Algorithm    
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast = head
        slow = head

        while fast and fast.next:
            fast = fast.next.next
            if slow == fast: return True

            slow = slow.next

        return False