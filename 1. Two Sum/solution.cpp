#include <vector>
#include <unordered_map>

using namespace std;

// Brute-Force Solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums.size(); j++){
                if ((i != j) && nums[i] + nums[j] == target) return vector<int> {i, j};
            }
        }

        return vector<int> {-1,-1};
    }
};

// Optimized Solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;

        for (int i = 0; i < nums.size(); i++){
            if (hashmap.find(target - nums[i]) != hashmap.end()){
                return vector<int> {hashmap[target - nums[i]], i};
            }

            else{
                hashmap[nums[i]] = i;
            }
        }

        return vector<int> {-1,-1};
    }
};