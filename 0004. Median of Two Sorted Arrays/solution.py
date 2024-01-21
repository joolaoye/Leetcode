class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        sortedArray = []
        var = 0

        while nums1 and nums2:
            if nums1[0] < nums2[0]:
                sortedArray.append(nums1[0])
                nums1 = nums1[1:]
            else:
                sortedArray.append(nums2[0])
                nums2 = nums2[1:]
        else:
            if nums1:
                sortedArray.extend(nums1)
            elif nums2:
                sortedArray.extend(nums2)

        if (len(sortedArray) - 1) % 2 == 0:
            median = sortedArray[(len(sortedArray) - 1)//2]
        else:
            upper = round(float(len(sortedArray) - 1)/2)
            lower = (len(sortedArray) - 1)//2
            median = (float(sortedArray[int(upper)]) + float(sortedArray[lower])) / 2

        return median
