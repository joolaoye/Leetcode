class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

# Brute Force Solution
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        def access_linkedList(rootNode, value_list=None):
            if value_list == None:
                value_list = []
            if rootNode.next == None:
                value_list.append(str(rootNode.val))
                return int("".join(value_list[::-1]))
            value_list.append(str(rootNode.val))
            return access_linkedList(rootNode.next, value_list)
        

        def create_linkedList(reversed_array, head=None):
            if not len(reversed_array):
                head.next == None
                return head
            if not head:
                head = ListNode(reversed_array.pop())
            if len(reversed_array):
                head.next = ListNode(reversed_array.pop())
                create_linkedList(reversed_array, head.next)
            return head
        

        return create_linkedList(list(str(access_linkedList(l1) + access_linkedList(l2))))
    
# Optimized Brute Force Solution
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        def linkedlist_to_str(node):
            if node is None: return ""

            tail = node
            res = ""

            while tail:
                res += str(tail.val)
                tail = tail.next

            return res[::-1]

        
        def str_to_linkedlist(string):
            dummy = ListNode()
            tail = dummy

            for char in string:
                tail.next = ListNode(int(char))
                tail = tail.next

            return dummy.next


        ans = int(linkedlist_to_str(l1)) + int(linkedlist_to_str(l2))

        return str_to_linkedlist(str(ans)[::-1])
    

# Optimized Solution
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode()
        tail = dummy
        carry = 0

        while l1 or l2 or carry:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            res = v1 + v2 + carry

            carry = res // 10

            tail.next = ListNode(res % 10)

            tail = tail.next

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None


        return dummy.next