// Kadene's Algorithm
int maxSubArray(int* nums, int numsSize){
    int max_sum = -1000000000;
    int current_sum = 0;

    for (int i = 0; i < numsSize; i++)
    {
       current_sum = (current_sum + nums[i] > nums[i]) ? current_sum + nums[i] : nums[i];
        max_sum = (max_sum > current_sum) ? max_sum : current_sum;
    }
    return max_sum;

}