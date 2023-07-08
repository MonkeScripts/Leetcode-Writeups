#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
class MyComp {
   public:
    // own implementation for comparing in prioroty queue
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    }
};
class Solution {
   public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::unordered_map<int, int> freq;
        // for priority queue, need to add the container and the comparator
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, MyComp> pq;
        // use an unordered map to record frequencies, an array does not work due to negative numbers
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
        }
        auto p = freq.begin();
        // add first k elements in
        for (int i = 0; i < k; ++i, ++p) {
            pq.push({p->first, p->second});
        }
        // add rest k elements in by comparison
        for (int i = k; i < freq.size(); ++i, ++p) {
            if (pq.top().second < p->second) {
                pq.pop();
                pq.push({p->first, p->second});
            }
        }
        // add to result vector
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};