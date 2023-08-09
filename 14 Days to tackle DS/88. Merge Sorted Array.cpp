//merge two arrays into one. m and n represents the size of the vectors
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pointer1 = 0;
        int pointer2 = 0;
        vector<int> result;
        while(pointer1 + pointer2 < nums1.size()){
            if(pointer1 < m && (pointer2 >=n || nums1[pointer1] < nums2[pointer2])){
                result.push_back(nums1[pointer1]);
                pointer1 ++;
                continue;
            }
            result.push_back(nums2[pointer2]);
            pointer2 ++;
        }
        nums1 = result;
    }
};
