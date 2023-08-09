//Given 2 arrays, return a new array with all overlapping elements
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int freq1[1001]= {0};
        int freq2[1001] ={0};
        vector<int> result;
        //record the frequencies in a hash table
        for(int i = 0; i<nums1.size();++i){
            freq1[nums1[i]]++;
        }
        for(int i = 0; i<nums2.size();++i){
            freq2[nums2[i]]++;
        }
        for(int i =0; i<1001;++i){
            int totalfreq = min(freq1[i],freq2[i]);
            if(totalfreq == 0) continue;
            //add the numbers to new result vector 
            for(int j = 0; j<totalfreq;++j) {
                result.push_back(i);
            }
        }
        return result;
    }
};
