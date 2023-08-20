class Solution {
public:
    int helper(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxCost = INT_MIN;
        for(int k=i;k<=j;k++){
            int cost = (nums[i-1] * nums[k] * nums[j+1]) + helper(i, k-1, nums, dp) + helper(k+1, j, nums, dp);
            maxCost = max(maxCost, cost);
        }
        return dp[i][j] = maxCost;
        
    }
    
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>>dp(n+2, vector<int>(n+2, 0));
        // return helper(1, n, nums, dp);
        for(int i=n;i>=1;i--){
            for(int j=1; j<=n;j++){
                if(i>j) continue;
                int maxCost = INT_MIN;
                for(int k=i;k<=j;k++){
                    int cost = (nums[i-1] * nums[k] * nums[j+1]) + dp[i][k-1] + dp[k+1][j];
                    maxCost = max(maxCost, cost);
                }
                dp[i][j] = maxCost;
            }
        }
        return dp[1][n];
    }
};
