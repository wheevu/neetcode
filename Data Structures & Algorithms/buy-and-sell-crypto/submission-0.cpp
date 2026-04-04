class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // idea: keep track of lowest price so far
        // every day, check the highest profit from current price and the lowest price so far
        // update the highest profit every day, return highest profit        
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};