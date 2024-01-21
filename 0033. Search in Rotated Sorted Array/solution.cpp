#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;

        while(l <= r){
            mid = (l + r) / 2;

            if (nums[mid] == target){
                return mid;
            }

            else if (nums[l] <= nums[mid]){
                if (target > nums[mid] || nums[l] > target){
                    l = mid + 1;
                }

                else{
                    r = mid - 1;
                }
            }

            else{
                if (target > nums[r] || target < nums[mid]){
                    r = mid - 1;
                }

                else{
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};
