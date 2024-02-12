// Kadene's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = INT_MIN / 10;
        int maxsum = INT_MIN / 10;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > cur + nums[i]){
                cur = nums[i];
            }

            else{
                cur = cur + nums[i];
            }

            if (cur > maxsum){
                maxsum = cur;
            }
        }

        return maxsum;
        
    }
};