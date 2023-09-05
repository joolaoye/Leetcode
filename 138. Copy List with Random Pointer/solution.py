"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
# Hashmap Solution
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        # First copy the linked list without random pointers
        # Store each node of the copied linked list in a python dict
        # The traverse the linked list again to set the random pointers

        if not head: return None

        hashmap = dict()

        dummy = Node(0)
        tail = dummy
        temp = head

        while temp:
            tail.next = Node(temp.val)
            hashmap[temp] = tail.next

            temp = temp.next
            tail = tail.next

        tail = dummy.next

        while head:
            if head.random:
                tail.random = hashmap[head.random]

            head = head.next
            tail = tail.next

        return dummy.next
    
# Optimized Hashmap Solution
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head: return None

        hashmap = dict()

        dummy = Node(0)
        tail = dummy
        temp = head

        while temp:
            if temp not in hashmap:
                hashmap[temp] = Node(temp.val)
            if temp.random and temp.random not in hashmap:
                hashmap[temp.random] = Node(temp.random.val)

            tail.next = hashmap[temp]
            tail.next.random = hashmap[temp.random] if temp.random else None

            temp = temp.next
            tail = tail.next

        return dummy.next