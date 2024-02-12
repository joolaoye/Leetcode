#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        auto rightmost = -1, leftmost = -1;

        while (l <= r){
            auto mid = (r + l) / 2;

            if (nums[mid] > target){
                r = mid - 1;
            }

            else if (nums[mid] < target){
                l = mid + 1;
            }

            else{
                rightmost = mid;
                l = mid + 1;
            }
        }

        l = 0, r = nums.size() - 1;
        while (l <= r){
            auto mid = (r + l) / 2;

            if (nums[mid] > target){
                r = mid - 1;
            }

            else if (nums[mid] < target){
                l = mid + 1;
            }

            else{
                leftmost = mid;
                r = mid - 1;
            }
        }

        return std::vector<int> {leftmost, rightmost};
    }
};
