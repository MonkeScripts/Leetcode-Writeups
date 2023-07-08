#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
   public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> hash;
        std::vector<std::vector<std::string>> result;
        for (int i = 0; i < strs.size(); ++i) {
            std::string temp = strs[i];
            std::sort(strs[i].begin(), strs[i].end());
            // adds the sorted string into a hash map
            // append to the vector if the sorted string is alr found
            // else make a new key and value pair
            hash[strs[i]].push_back(temp);
        }
        for (auto i : hash) {
            result.push_back(i.second);
        }
        return result;
    }
};