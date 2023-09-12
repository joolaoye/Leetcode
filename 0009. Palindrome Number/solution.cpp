// Optimized solution
class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0){
            return false;
        }


        long res = 0;
        int tmp = x;

        while (tmp > 0){
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }

        return x == res;
        
    }
};