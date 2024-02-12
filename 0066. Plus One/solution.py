class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1

        for i in range(len(digits) - 1, -1, -1):
            res = digits[i] + carry

            digits[i] = res % 10
            carry = res // 10

        if carry:
            digits = [carry] + digits

        return digits
    