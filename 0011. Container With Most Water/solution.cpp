#include <algorithm>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int temp;
        int maxarea = (r - l) * std::min(height[l], height[r]);

        while (l < r){
            temp = (r - l) * std::min(height[l], height[r]);
            maxarea = (temp > maxarea) ? temp : maxarea;
            if (height[l] > height[r]){
                r--;
            }
            else if (height[l] < height[r]){
                l++;
            }
            else{
                l++;
                r--;
            }

        }

        return maxarea;
    }
};
