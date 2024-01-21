/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let res = [0,0];

    let hashmap = {};


    for(let i = 0; i < nums.length; i++){
       let diff = target - nums[i]
        if (diff in hashmap){
            res[0] = hashmap[diff]
            res[1] = i
            return res;


        }
        else{
            hashmap[nums[i]] = i

        }
    }

};
