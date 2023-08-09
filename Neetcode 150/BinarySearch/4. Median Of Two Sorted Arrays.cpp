#include <limits.h>

#include <iostream>
#include <vector>
class Solution {
   public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        // we know that there would be 2 halfs (left and right partition) in the merged sorted array
        // the algorithm mainly revolves around how many elements we add from nums2 to nums1
        int total = m + n;
        int low = 0;
        int high = m;
        double result = 0.0;
        while (low <= high) {
            // nums1
            int i = low + (high - low) / 2;
            // nums2
            int j = (total + 1) / 2 - i;
            // left1 refers to the last element in the left partition in nums1;
            int left1 = (i > 0) ? nums1[i - 1] : INT_MIN;
            // right1 refers to the first element in the excluded right partition in nums1;
            int right1 = (i < m) ? nums1[i] : INT_MAX;
            // left2 refers to the last element in the left partition in nums2;
            int left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            // right2 refers to the first element in the right partition in nums2;
            int right2 = (j < n) ? nums2[j] : INT_MAX;
            // checks if last elements in left partition1 is smaller than that of first right partition2 and vice versa
            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 == 0) {
                    return result = (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
                }
                return result = std::max(left1, left2);
            }
            // included too many elements
            if (left1 > right2) {
                high = i - 1;
                continue;
            }
            // include too little elements
            low = i + 1;
        }
        return result;
    }
};