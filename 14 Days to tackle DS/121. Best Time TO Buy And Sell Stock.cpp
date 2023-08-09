class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = 0;
        int profit = 0;
        for(int i = 0; i< prices.size()-1;++i){
            int j = i + 1;
            //find min value to buy
            buy = min(buy,prices[j]);
            //find the best time to sell
            sell = max(sell,prices[j]);
            //maximise profit
            profit= max(profit,sell-buy);
            sell = 0;
        }
        return profit;
    }
};
