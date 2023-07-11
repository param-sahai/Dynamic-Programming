class Solution {
public:
    
//         int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
//             if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size()) return 1e9;
//             if(i==0) return matrix[i][j];
//             if(dp[i][j]!=-1) return dp[i][j];
//             return dp[i][j] = matrix[i][j] + min( helper(i-1, j, matrix, dp),
//                 min(helper(i-1, j-1, matrix, dp), helper(i-1, j+1, matrix, dp)));

//         }
    
    /*
    // Memoization - TLE
    // T.C.: O(n x m)
    // S.C.: O(n x m) + O(n x m) - stack + dp
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        int res = 1e9;
        for(int col = 0; col<m; col++){
            res = min( helper(n-1, col, matrix, dp), res);
        }
        return res;
    }
    */
    
    /*
    // Tabulation
    // T.C.: O(n x m)
    // S.C.: O(n x m) - dp
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    dp[i][j] = matrix[i][j];
                    continue;
                }
                int top = INT_MAX, leftd = INT_MAX, rightd = INT_MAX;
                if(i-1 >= 0) top = dp[i-1][j];
                if(i-1 >= 0 && j-1>=0) leftd = dp[i-1][j-1];
                if(i-1 >= 0 && j+1<m) rightd = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min(top, min(leftd, rightd));
                
            }
        }
        int res = INT_MAX;
        for(int col = 0; col<m; col++){
            res = min( dp[n-1][col], res);
        }
        return res;
    }
    */
    
    
    // Space Optimization
    // T.C.: O(n x m)
    // S.C.: O(m + m) == O(m) - prev + curr
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m, 0);
        
        for(int i=0;i<n;i++){
            vector<int> curr(m, 0);
            for(int j=0;j<m;j++){
                if(i==0){
                    curr[j] = matrix[i][j];
                    continue;
                }
                int top = INT_MAX, leftd = INT_MAX, rightd = INT_MAX;
                if(i-1 >= 0) top = prev[j];
                if(i-1 >= 0 && j-1>=0) leftd = prev[j-1];
                if(i-1 >= 0 && j+1<m) rightd = prev[j+1];
                curr[j] = matrix[i][j] + min(top, min(leftd, rightd));
                
            }
            prev = curr;
        }
        int res = INT_MAX;
        for(auto x: prev){
            res = min(x, res);
        }
        
        return res;
        
    }    
    
};
