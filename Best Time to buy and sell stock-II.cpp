class Solution {
public:
    int helper(int i, int buy, vector<int>& prices, vector<vector<int>>&dp){
        
        //Base Case
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit = 0;
        if(buy) //we can buy stock
        {
            //Take
            int op1 =0, op2=0;
            op1= -prices[i] + helper(i+1, 0, prices, dp);
            
            //Not Take
            op2 = 0 + helper(i+1, 1, prices, dp);
            
            profit = max(op1, op2);
            
        }
        else{
            int op1 =0, op2=0;
            
            //Sell
            op1 = prices[i] + helper(i+1, 1, prices, dp);
                        
            //Not Sell
            op2 = helper(i+1, 0, prices, dp);
            
            profit = max(op1, op2);
        }
        
        return dp[i][buy] = profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        //memoization
        // vector<vector<int>>dp(n+1, vector<int>(2, -1));
        // return helper(0, 1, prices, dp);
        
        vector<int>prev(2, 0);
        vector<int>curr(2, 0);
        
        //tabulation
        
        //base case
        curr[0] = 0;
        curr[1] = 0;
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                if(buy) //we can buy stock
                {
                    //Take
                    int op1 =0, op2=0;
                    op1= -prices[i] + curr[0];
            
                    //Not Take
                    op2 = 0 + curr[1];
            
                    profit = max(op1, op2);
            
                    }
                else{
                    int op1 =0, op2=0;

                    //Sell
                    op1 = prices[i] + curr[1];

                    //Not Sell
                    op2 = curr[0];

                    profit = max(op1, op2);
                }
        
                prev[buy] = profit;
                
                curr = prev;
            }
        }
        
        return curr[1];
        
    }
};
