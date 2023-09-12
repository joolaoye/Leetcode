# Newton-Raphson Iterative Solution
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        curr = 0
        prev = 1

        while True:
            curr = prev - (float(float(prev * prev) - x) / float(2 * prev))
            if round(curr) == round(prev):
                break
            prev = curr
        return int(curr)
    

# Binary Search Solution
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        l,r = 0, x
        res = 0

        while l <= r:
            mid = (l + r) // 2

            if (mid**2 == x): return mid

            if (mid**2 > x): r = mid - 1

            if (mid**2 < x):
                res = mid 
                l = mid + 1
        
        return res