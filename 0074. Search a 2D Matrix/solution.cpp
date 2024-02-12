#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = 0;
        int n = matrix.size() - 1;
        int last_index = matrix[m].size() - 1;
        int mid;

        while (m <= n){
            mid = (m + n) / 2;

            if (target > matrix[mid][last_index]){
                m = mid + 1;
            }

            else if (target < matrix[mid][0]){
                n = mid - 1;
            }

            else{
                break;
            }
        }
    
        if (m > n){
            return false;
        }

        int l = 0;
        int r = matrix[l].size() - 1;

        int row = (m + n) / 2;

        while (l <= r){
            mid = (r + l) / 2;

            if (target > matrix[row][mid]){
                l = mid + 1;
            }

            else if (target < matrix[row][mid]){
                r = mid - 1;
            }

            else{
                return true;
            }
        }

        return false;

    }
};
