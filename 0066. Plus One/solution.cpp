#include <vector> 

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::vector<int> res;
        int carry = 1;

        for (int i = digits.size() - 1; i >= 0; i -= 1){
            int val = digits[i] + carry;
            carry = val / 10;
            res.push_back(val % 10);
        }

        if (carry){
            res.push_back(carry);
        }

        int l = 0, r = res.size() - 1;

        while (l < r){
            int tmp = res[l];
            res[l] = res[r];
            res[r] = tmp;

            l += 1;
            r -= 1; 
        }
        
        return res;
    }
};
