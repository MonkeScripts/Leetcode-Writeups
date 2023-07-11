#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
class Solution {
   public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        // rather than counting each turn, we sort the cars and check how many turns it takes for them to complete the road
        // we use a pair so that when we sort the cars based on position we also remember their corresponding speed
        std::vector<std::pair<int, int>> sorting_pair;
        for (int i = 0; i < position.size(); ++i) {
            sorting_pair.push_back({position[i], speed[i]});
        }
        std::sort(sorting_pair.begin(), sorting_pair.end());
        std::stack<float> turnsStack;
        for (int i = 0; i < sorting_pair.size(); ++i) {
            // check number of turns
            float turns = ((float)(target - sorting_pair[i].first)) / (float)sorting_pair[i].second;
            // since everything is sorted and we know that a fleet depends on the slowest car
            // we realise that this is a monotonic decreasing stack, where we keep track of the highest turns for each fleet when we iterate through the cars
            while (!turnsStack.empty() && turns >= turnsStack.top()) {
                turnsStack.pop();
            }
            turnsStack.push(turns);
        }

        return turnsStack.size();
    }
};