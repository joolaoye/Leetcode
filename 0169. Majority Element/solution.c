// Boyer-Mayor Voting Algorithm
int majorityElement(int* nums, int numsSize){
    int cand = nums[0];
    int count = 1;

    for (int i = 1; i < numsSize; i++){
        if (nums[i] == cand) count++;

        else count--;

        if (count == 0){ 
        cand = nums[i];
        count = 1;
        }
    }

    return cand;
}