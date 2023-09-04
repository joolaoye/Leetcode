# Problem Description

Given an array of integers ```nums``` and an integer ```target```, return indices of the two numbers such that they add up to ```target```.

You may assume that each input would have ***exactly one solution***, and you may not use the same element twice.

You can return the answer in any order.

 

**Example 1:**
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```
**Example 2:**
```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```
**Example 3:**

```
Input: nums = [3,3], target = 6
Output: [0,1]
```
 

### Constraints:

```2 <= nums.length <= 104```
```-109 <= nums[i] <= 109```
```-109 <= target <= 109```
**Only one valid answer exists.**
 

**Follow-up**: Can you come up with an algorithm that is less than O(n2) time complexity?

# Solution

I will be going over two solutions: the brute force solution and the optimized solution

##  Brute Force Solution
I mostly start out with a brute force solution for every problem, then work my way through optimizing it. There is a saying  "*Every good programmer should be able to come up with a brute force approach to a difficult problem*". 

#### Approach
In this approach, for every element in the array we take a subarray that doesn't contain the current element, then check for the element in this subarray that when added to the current element sums up to the target, then we return our result. This approach is fairly intuitive and we are assured that each test case has a solution.

### Algorithm
* Create an empty result array of size 2 
```result_array = empty array of size 2```
* Iterate over each element of the input array
``` for i from 0 to length(input_array) - 1```
    * For each element visited, iterate over the array again excluding the current element.
    ``` for j from 0 to length(input_array) - 1 and j != i```
        * Check if the current pair of elements adds up to the targe
        ``` if input_array[i] + input_array[j] == target```
            * if step5 is true, populate the result array witht the indices of both elements then return the result
            ``` result_array = {i,j}```
            ```return result_array```

### Worst-Case Complexity Analysis
**Time Complexity:** Given an input array of size n, we iterate over the array n times in the outer loop. For each iteration of the outer loop, we iterate over the array (n - 1) times in the inner loop, excluding the current element. This results in a total of n * (n - 1) operations. When we consider the most significant term, this simplifies to O(n^2). Therefore, this algorithm is bounded by O(n^2) time.

**Space Complexity:** Fortunately, the space complexity of this algorithm does not scale with the input length. The only additional space used is for the result array, which has a fixed size of 2 elements. In Big O notation, we classify this as constant space complexity, denoted as O(1). Therefore, this algorithm uses O(1) space.






