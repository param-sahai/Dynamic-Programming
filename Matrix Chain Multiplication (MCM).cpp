// gfg - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303

class Solution{
public:
    int helper(int i, int j, int arr[], int n, vector<vector<int>> &dp) //function that return the min number of multiplication required from ith Matrix to jTH
    {
        if(i==j) return 0; //single matrix;
        if(dp[i][j]!=-1) return dp[i][j];
        int mn = 1e9;
        for(int k=i;k<=j-1;k++){
            int numberMulti = (arr[i-1] * arr[k] * arr[j]) + helper(i, k, arr, n, dp) + helper(k+1, j, arr, n, dp);
            mn = min(numberMulti, mn);
        }
        return dp[i][j] = mn;
        
        
        
        
    }
    int matrixMultiplication(int N, int arr[])
    {
        /*
        //Memoization
        vector<vector<int>>dp(N, vector<int>(N, -1));
        return helper(1, N-1, arr, N, dp); //starting from 1st array to n-1th;
        */
        
        
        //Tabulation - Bottom Up
         vector<vector<int>>dp(N, vector<int>(N, 0));
         
        //Base Cases
        // for(int i=1;i<=N-1;i++){ \\Not Required since dp already initialized with 0
        //     dp[i][i] = 0;
        // }
        
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<=N-1;j++){
                int mn = 1e9;
                for(int k=j-1;k>=i;k--){
                    int numberMulti = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                    mn = min(numberMulti, mn);
                }
                dp[i][j] = mn;
            }
        }
        return dp[1][N-1];
        
    }
};
