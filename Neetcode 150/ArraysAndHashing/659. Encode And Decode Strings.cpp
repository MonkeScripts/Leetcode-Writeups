#include <iostream>
#include <string>
#include <vector>
class Solution {
   public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    std::string encode(std::vector<std::string> &strs) {
        // write your code here
        std::string result = "";
        for (int i = 0; i < strs.size(); ++i) {
            result += std::to_string(strs[i].size());
            result += '_';
            result += strs[i];
        }
        return result;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    std::vector<std::string> decode(std::string &str) {
        // write your code here
        std::vector<std::string> result;
        int i = 0;
        //<length>_word
        while (i < str.size()) {
            int j = i;
            while (str[j] != '_') {
                j++;
            }
            // cout<<str.substr(i,j-i);

            std::string _len = str.substr(i, j - i);
            int len = stoi(_len);
            std::string num_string = str.substr(j + 1, len);
            result.push_back(num_string);
            i = j + 1 + len;
        }
        return result;
    }
};