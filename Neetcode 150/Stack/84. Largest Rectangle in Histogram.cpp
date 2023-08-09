#include <iostream>
#include <stack>
#include <vector>
class Solution {
   public:
    int largestRectangleArea(std::vector<int>& heights) {
        int result = 0;
        heights.push_back(0);
        std::stack<int> monoIncreasing;
        for (int i = 0; i < heights.size(); ++i) {
            // we create this monotonic increasing stack so that whenever we encounter a lower value,
            // we can use this value and calculate all the possible areas
            while (!monoIncreasing.empty() && heights[i] <= heights[monoIncreasing.top()]) {
                int greatestHeight = heights[monoIncreasing.top()];
                monoIncreasing.pop();
                int left = monoIncreasing.size() ? monoIncreasing.top() : -1;
                int right = i - 1;
                result = std::max(result, greatestHeight * (right - left));
            }
            monoIncreasing.push(i);
        }
        return result;
    }
};