class Solution {
public:
    int helper(int i, int j, vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = helper(i, j-1, dp);
        int up = helper(i-1, j, dp);
        return dp[i][j] = left+up;
    }
    
    
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        // return helper(m-1, n-1, dp);
        
        // dp[0][0] = 1;
        
        vector<int>prev(n, 0);
        
        for(int i=0;i<m;i++){
            vector<int>curr(n, 0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=1;
                else{
                    int left = 0, up = 0;
                    if(j-1 >= 0) left = curr[j-1];
                     up = prev[j];
                    curr[j] = left+up;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
