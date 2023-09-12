// Boyer-Mayor Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == cand) count++;

            else count--;

            if (count == 0){ 
            cand = nums[i];
            count = 1;
            }
        }

        return cand;
    
    }
};