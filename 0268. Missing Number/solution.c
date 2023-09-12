int missingNumber(int* nums, int numsSize){
    int real_sum = (numsSize * (numsSize + 1)) / 2;

    int nums_sum = 0;

    for (int i = 0; i < numsSize; i++) nums_sum += nums[i];

    return real_sum - nums_sum;
}