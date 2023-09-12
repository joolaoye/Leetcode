# Brute Force Solution
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        a = x
        val = []
        reverse = 0
        while a > 0:
            val.append(a % 10)
            a = a // 10

        for i in range(len(val)):
            reverse += val[i] * (10 **((len(val) - 1 - i)))

        return reverse == x
    
# Optimized Solution    
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        rev, num = 0,x

        while num > 0:
            rev = rev * 10 + num % 10
            num //=10

        return x == rev