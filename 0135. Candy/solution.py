class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        distro = [1] * len(ratings)

        for i in range(len(ratings)):
          if i > 0 and ratings[i] > ratings[i - 1]:
            distro[i] = max(distro[i - 1] + 1, distro[i])

        for j in range(len(ratings) - 1, -1, -1):
          if j < len(ratings) - 1 and ratings[j] > ratings[j + 1]:
            distro[j] = max(distro[j + 1] + 1, distro[j])
    

        return sum(distro)
        