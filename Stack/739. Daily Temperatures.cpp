#include <iostream>
#include <stack>
#include <vector>

class Solution {
   public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        // implements a monotonic decreasing stack
        std::stack<int> greaterStack;
        // start from the back,add the index of the numbers to the stack,pop the stack if current number is larger than the top of the stack
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!greaterStack.empty() && temperatures[greaterStack.top()] <= temperatures[i]) greaterStack.pop();
            if (!greaterStack.empty()) result[i] = greaterStack.top() - i;
            greaterStack.push(i);
        }
        return result;
    }
};