class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0, minp = prices[0];
        for(int i=1;i<n;i++){
            int buy = prices[i];
            profit = max(profit, buy - minp);
            minp = min(minp, prices[i]);
        }
        return profit;
    }
};
