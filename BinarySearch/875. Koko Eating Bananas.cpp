#include <iostream>
#include <vector>

class Solution {
   public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        int result = 0;
        // find the highes banana in one pile
        // this is the maximum number of bananas that koko needs to eat in one hour
        for (int i = 0; i < piles.size(); ++i) {
            right = std::max(right, piles[i]);
        }
        // once we obtain a maximum, we can do a binary search to find the smallest necessary
        while (left <= right) {
            long middle = left + (right - left) / 2;
            long minHours = 0;
            // loop through piles,add up all the hours needed
            for (int i = 0; i < piles.size(); ++i) {
                // minHours += (piles[i] + middle - 1) / middle;
                // in the event of remainders, we have to add one hour
                if (piles[i] % middle > 0) minHours++;
                minHours += piles[i] / middle;
            }
            // cannot immediately short circuit and return middle because there could be better min k out there
            // updating result must only be in the if because only then the result is valid
            if (minHours <= h) {
                result = middle;
                right = middle - 1;
            } else
                left = middle + 1;
        }
        // trick is to have a variable to store the result rather than immediately returning once the hours are met
        return result;
    }
};