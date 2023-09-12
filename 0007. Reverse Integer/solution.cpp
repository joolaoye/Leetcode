#define INT_MIN -2147483648
#define INT_MAX 2147483647

// Optimized Solution
class Solution {
public:
    int reverse(int x) {
        int mult;

        if (x < 1){
            mult = -1;
        }
        else{
            mult = 1;
        }

        x = mult * (long) x;

        long long res = 0;

        while (x > 0){
            res = res * 10 + x % 10;
            x /= 10;
        }

        if ((res > INT_MAX) || (res < INT_MIN)) return 0;
        
        return res * mult;
        
    }
};