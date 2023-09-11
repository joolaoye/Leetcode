class Solution(object):
    def groupThePeople(self, groupSizes):
        """
        :type groupSizes: List[int]
        :rtype: List[List[int]]
        """
        res = []
        hashmap = {}

        for i in range(len(groupSizes)):
            if groupSizes[i] in hashmap:
                hashmap[groupSizes[i]].append(i)

            else:
                hashmap[groupSizes[i]] = [i]

            if len(hashmap[groupSizes[i]]) == groupSizes[i]:
                res.append(hashmap[groupSizes[i]])
                del hashmap[groupSizes[i]]

        return res
            