class Solution {
public:
      
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>ahead(5, 0);
        vector<int>curr(5, 0);
        
        //Space Optimization
        for(int i=n-1; i>=0; i--){
            for(int trn=3; trn>=0; trn--){
                int profit=0;
                 if(trn%2==0){ //    Even transaction == Buy
                    profit = max(-prices[i] + ahead[trn+1], ahead[trn]);
                }
                else //Odd Transaction == Sell
                    profit = max(prices[i] + ahead[trn+1], ahead[trn]);

                curr[trn]=profit;
            }
            ahead = curr;
        }
        
        return curr[0];
    }
};
