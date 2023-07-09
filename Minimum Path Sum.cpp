class Solution {
public:
  
    /*
    //Memoization
    //T.C. = O(m*n) 
    //S.C. = O(m*n) + O(m*n) - stack space + dp    
    
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        int left = INT_MAX, up = INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        if(j-1>=0) left = grid[i][j] + helper(i, j-1, grid, dp);
        if(i-1>=0) up = grid[i][j] + helper(i-1, j, grid, dp);
        return dp[i][j] = min(left, up);
        
    }
    */
    
    
    /*
    //Tabulation
    //T.C. = O(m*n) 
    //S.C. = O(m*n) - dp
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        // return helper(m-1, n-1, grid, dp);
        
        dp[0][0] = grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int left = INT_MAX, up = INT_MAX;
                if(j-1>=0) left = grid[i][j] + dp[i][j-1];
                if(i-1>=0) up = grid[i][j] + dp[i-1][j];
                dp[i][j] = min(left, up);
            }
        }
        return dp[m-1][n-1];
    }
    */
    
    //Space Optimization
    //T.C. = O(m*n) 
    //S.C. = O(2*n) - prev + curr
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>prev(n, 0);
        
        for(int i=0;i<m;i++){
            vector<int>curr(n, 0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j] = grid[i][j];
                else{
                    int left = INT_MAX, up=INT_MAX;
                    if(j-1>=0) 
                        left = grid[i][j] + curr[j-1];
                    if(i-1>=0)
                        up = grid[i][j] + prev[j];
                    curr[j] = min(left, up);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
