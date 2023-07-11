#include <iostream>
#include <stack>
#include <utility>
#include <vector>

class MinStack {
   public:
    MinStack() {
    }

    void push(int val) {
        // if top of the stack has a higher minimum value than the current val, push {val,val}
        if (stack.empty() || stack.end()[-1].second > val) {
            stack.push_back({val, val});
            return;
        }
        // else keep current minimum
        stack.push_back({val, stack.end()[-1].second});
    }

    void pop() {
        stack.pop_back();
    }

    int top() {
        return stack.end()[-1].first;
    }

    int getMin() {
        return stack.end()[-1].second;
    }

   private:
    // create a stack of pairs, with the second value storing the current minimum value
    std::vector<std::pair<int, int>> stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */