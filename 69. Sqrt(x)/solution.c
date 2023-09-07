int mySqrt(int x){
    long l = 0;
    long r = x;
    long res;

    while (l <= r){
        long mid = (l + r) / 2;

        if (mid * mid == x){
            return mid;
        }

        else if (mid * mid > x){
            r = mid - 1;
        }

        else{
            res = mid;
            l = mid + 1;
        }
    }


    return res;    
}