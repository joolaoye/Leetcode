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

I will be going over two solutions: ***brute force solution*** and ***optimized solution***

##  Brute Force Solution
I mostly start out with a brute force solution for every problem, then work my way through optimizing it. There is a saying  "*Every good programmer should be able to come up with a brute force approach to a difficult problem*". 

#### Approach
In this approach, for every element in the array we take a subarray that doesn't contain the current element, then check for the element in this subarray that when added to the current element sums up to the target, then we return our result. This approach is fairly intuitive and we are assured that each test case has a solution.

### Algorithm
* Create an empty result array of size 2

```result_array = empty array of size 2```

* Iterate over each element of the input array

    ``` for i from 0 to length(input_array) - 1```

    * For each element visited, iterate over the array again excluding the current element

        ``` for j from 0 to length(input_array) - 1 and j != i```

        * Check if the current pair of elements adds up to the target

            ``` if input_array[i] + input_array[j] == target```

            * if step4 is true, populate the result array witht the indices of both elements then return the result

            ``` result_array = {i,j}```
            
            ```return result_array```

### Worst-Case Complexity Analysis
**Time Complexity:** Given an input array of size n, we iterate over the array n times in the outer loop. For each iteration of the outer loop, we iterate over the array (n - 1) times in the inner loop, excluding the current element. This results in a total of n * (n - 1) operations. When we consider the most significant term, this simplifies to O(n^2). Therefore, this algorithm is bounded by O(n^2) time.

**Space Complexity:** Fortunately, the space complexity of this algorithm does not scale with the input size. The only additional space used is for the result array, which has a fixed size of 2 elements. In Big O notation, we classify this as constant space complexity, denoted as O(1). Therefore, this algorithm is bounded by O(1) space.

# Optimized Solution
If you notice in the brute-force approach, we are doing twice as many work by checking pairs of elements in both directions (a, b and b, a). So, can we do better? Yes,  we can improve this using the concept of memoization, which involves storing the results of previously computed values for quick access

### Approach
Let me propose, that for each element we visit, we store it's value and it's index in some fast access data structure. What fast data structure allows you store key,value pairs ? ***The hashmap***

So as we iterate through the input array this time around, we store each element's value as the key and its index as the value in a hashmap

For each subsequent element, we check if the difference between the target value and the current element exists in our hashmap. This lookup operation is fairly constant in time complexity.

When we find a pair that adds up to the target value, we use the hashmap to retrieve the index of the complementary element. We also have the index of our current element. With these two indices, we can populate our result array and return it

This optimized approach is similar to the initial approach but leverages memoization with a hashmap to significantly improve efficiency. It reduces the need for redundant element comparisons, resulting in faster execution

**But what if there is duplicate element?** We overwrite the value of that key with the current index. Remember, we are rest assured there is only one solution so nothing to be worried about

### Algorithm
* Create an empty result array of size 2 

```result_array = empty array of size 2```
* Create an hashmap equivalent in your language 

``` Python: hashmap = dict()```

``` C++: unordered_map<int, int> hashmap;```
* Iterate over each element of the input array

    ``` for i from 0 to length(input_array) - 1```
    * Calculate the difference between the target value and the current element

    ```diff = target - input_array[i]```
    * Check if the difference exists in our hashmap

        ``` Python: if diff in hashmap ```
        
        ``` C++: if (hashmap.find(diff) != hashmap.end()) ```
        * If step5 is true, retrieve the index of the complementary element from the hashmap

            ``` Python: i = hashmap[diff] ```

            ``` C++: i = hashmap[diff] ```

            * Populate the result array witht the indices of both elements then return the result

            ```result_array = {i, j}```

            ```return result_array```

### Worst-Case Complexity Analysis
**Time Complexity:** Given an input array of size n, we iterate over the array n times. For each iteration, we compute the difference of the target value and the current element, then we check if this difference is in our hashmap, hashmap has a constant lookup time as well as subtraction on standard sized integers, so thats O(2) in the inner loop, putting together, O(2n), which simplifies to O(n) since n is the most significant term. Therefore, this algorithm is bounded by O(n) time.


**Space Complexity:** The space complexity of this algorithm scales linearly with the input size. We create a result array of fixed size, which is O(1). However, the hashmap's space requirements depends on the number of unique elements. In the worst case, if the complementary element is found at the end of the array and all the elements are unique, we would need to store n - 1 elements in our hashmap. Therefore, the space complexity is bounded by O(n) space.






