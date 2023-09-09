class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int real_sum = (nums.size() * (nums.size() + 1)) / 2;

        int nums_sum = 0;

        for (auto& num : nums) nums_sum += num;

        return real_sum - nums_sum;
    }
};