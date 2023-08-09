#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

class TimeMap {
   public:
    TimeMap() {
    }

    void set(std::string key, std::string value, int timestamp) {
        std::pair<int, std::string> stamp;
        stamp.first = timestamp;
        stamp.second = value;
        time_map[key].push_back(stamp);
    }

    std::string get(std::string key, int timestamp) {
        // need to add & so that we do not waste memory
        std::vector<std::pair<int, std::string>> &stamps = time_map[key];
        std::string result = "";
        int left = 0;
        int right = stamps.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (stamps[middle].first == timestamp) return stamps[middle].second;
            if (stamps[middle].first > timestamp) {
                right = middle - 1;
                continue;
            }
            result = stamps[middle].second;
            left = middle + 1;
        }
        return result;
    }
    // main challenge of this question is finding out the right data structure
    // in this case, we create an unordered map that maps the key to a vector with a pair(timestamp,value)
    // this is so that we can group all the values of the same key together
    // to get a specific value, we can just look up the key, do a binary search on the timestamp and find its value
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> time_map;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */