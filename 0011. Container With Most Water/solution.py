class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l,r = 0, len(height) - 1
        dh = float("-inf")

        while l < r:
            val = min(height[l], height[r]) * (r - l)

            if height[l] > height[r]:
                r -= 1

            elif height[l] < height[r]:
                l += 1

            else:
                l += 1
                r -= 1
            
            dh = max(dh, val)

        return dh
    