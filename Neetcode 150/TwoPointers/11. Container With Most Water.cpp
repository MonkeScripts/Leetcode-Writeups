#include <iostream>
#include <vector>

class Solution {
   public:
    int maxArea(std::vector<int>& height) {
        int result = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            // need to figure out the area of a water
            int area = (right - left) * std::min(height[left], height[right]);
            result = std::max(result, area);
            // move left and right pointers accordingly
            if (height[left] > height[right]) {
                right--;
                continue;
            }
            left++;
        }
        return result;
    }
};