class Solution {
public:
    
//     Recursive Solution
    int helper1(int n) {
        if(n<=1) return n;
        return fib(n-1) + fib(n-2);
    }
    
//      Memoization - Top-Down
    int helper2(int n, vector<int>&dp){
        if(n<=1) return dp[n] = n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = helper2(n-1, dp) + helper2(n-2, dp);      
    }
    
    
//      Tabulation - Botton Up (from Base Case)
    int helper3(int n, vector<int>&dp){
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }    
        return dp[n];
    }
    
//      Space Optimization    
    int helper4(int n){
        if(n<=1) return n;
        int prev, prev2, curr;
        prev = 0, prev2 = 1;
        for(int i=1;i<=n;i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }

    int fib(int n){
        // return helper1(n);
        
        // vector<int>dp(n+1, -1);
        // return helper2(n, dp);
        
        // vector<int>dp(n+1, -1);
        // dp[0] = 0;
        // if(n>0) dp[1] = 1; //edge case
        // return helper3(n, dp);
        
        
        return helper4(n);
    }
    
    /**
        COMPLEXITY ANALYSIS
        T.C = O(N)
            helper 2 - S.C. = O(N + N) Recursion stack and dp array
            helper 3 - S.C. = O(N) dp array
            helper 4 - S.C. = O(1) curr, prev, prev2
        **/
    
};
