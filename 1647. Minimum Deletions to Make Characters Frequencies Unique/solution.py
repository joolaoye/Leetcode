# Brute-force Solution
class Solution(object):
    def minDeletions(self, s):
        """
        :type s: str
        :rtype: int
        """
        hashmap = {}
        count = 0

        for i in range(len(s)):
            if s[i] not in hashmap:
                temp = 1

                for j in range(i + 1, len(s)):
                    if s[j] == s[i]:
                        temp += 1

                
                while temp > 0 and temp in hashmap.values():
                    temp -= 1
                    count += 1

                hashmap[s[i]] = temp

        
        return count
    

# Optimized Solution
class Solution(object):
    def minDeletions(self, s):
        """
        :type s: str
        :rtype: int
        """
        hashmap = {}
        count = 0

        for char in s:
            if char in hashmap:
                hashmap[char] += 1
            else:
                hashmap[char] = 1


        unique_freq = set()

        for freq in hashmap.values():
            while freq in unique_freq:
                freq -= 1
                count += 1

            if freq > 0:
                unique_freq.add(freq)

        return count