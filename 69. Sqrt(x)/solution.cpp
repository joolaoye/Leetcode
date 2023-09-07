class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int l = 0;
        int r = x;
        int res = 0;
        long mid;

        while (l <= r){
            mid = (l + r) / 2;

            if (mid * mid == x) return mid;

            if (mid * mid > x) r = mid - 1;

            if (mid * mid < x){
                res = mid;
                l = mid + 1;
            }
        }

        return res;
    }
};