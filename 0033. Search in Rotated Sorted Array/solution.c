int search(int* nums, int numsSize, int target){
    int l = 0, r = numsSize - 1;

    while (l <= r){
        int mid = (l + r) / 2;

        if (target == nums[mid]){
            return mid;
        }

        else if (nums[l] <= nums[mid]){
            if (nums[l] > target || target > nums[mid]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        else{
            if (nums[r] < target || target < nums[mid]){
                r = mid - 1;
            }

            else{
                l = mid + 1;
            }
        }
    }

    return -1;

}
