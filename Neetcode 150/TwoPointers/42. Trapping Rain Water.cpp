#include <iostream>
#include <vector>
class Solution {
   public:
    int trap(std::vector<int>& height) {
        // we need to figure out how do to calculate the amount of water trapped by one block
        // this can be deduced to be the min(left highest side, right highest side) - current height of the block(height[i])
        // we find this value for each indivdual block and then add them all up
        //  we can utilise pointers to check left and right side
        //  extra variables to store the left highest side and right highest side
        if (height.size() <= 2) return 0;
        int maxLeft = height[0];
        int maxRight = height[height.size() - 1];
        int left = 1;
        int right = height.size() - 2;
        int result = 0;
        // must remember the last block when the 2 pointers meet
        // when they meet there is the possibility of having one last crevice to be filled
        while (left <= right) {
            if (maxLeft < maxRight) {
                if (height[left] > maxLeft) {
                    maxLeft = height[left];
                } else {
                    result += maxLeft - height[left];
                }
                left++;
            } else {
                if (height[right] > maxRight) {
                    maxRight = height[right];
                } else {
                    result += maxRight - height[right];
                }
                right--;
            }
        }
        return result;
    }
};