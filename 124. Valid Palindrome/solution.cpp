#include <cctype>

// Two-pointers solution
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r){
            while ((l < r) and isalnum(s[l]) == 0){
                l += 1;
            }

            while ((r > l) and isalnum(s[r]) == 0){
                r -= 1;
            }

            if (tolower(s[l]) != tolower(s[r])){
                return false;
            }

            l += 1;
            r -= 1;
        }

        return true;
    }
};