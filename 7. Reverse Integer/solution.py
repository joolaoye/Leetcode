# Brute Force Solution
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        string = ''
        if x < 0:
            x *= - 1
            string += '-'
        elif x == 0:
            string += '0'

        while x > 0:
            string += str(x % 10)
            x = x // 10

        if -2**31 <= int(string) <= (2 ** 31) - 1:
            return int(string)
        else:
            return 0
        
# Optimized solution
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0 : mult = -1
        else : mult = 1

        temp = abs(x)
        res = 0

        while temp > 0:
            res = (res * 10) + temp % 10
            print(res)
            temp //= 10

        res *= mult

        if not (-1 * (2 ** 31) <= res <= (2 ** 31) - 1) : return 0

        return res