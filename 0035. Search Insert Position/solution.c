int searchInsert(int* nums, int numsSize, int target){
    int l = 0, r = numsSize - 1;

    while (l <= r){
        int mid = (l + r) / 2;

        if (nums[mid] == target){
            return mid;
        }

        else if (nums[mid] > target){
            r = mid - 1;
        }

        else if (nums[mid] < target){
            l = mid + 1;
        }
    }

    return l;
}