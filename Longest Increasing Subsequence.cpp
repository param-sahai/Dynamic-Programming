// #include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[prev]<nums[i])
                {
                    dp[i] = max(1 + dp[prev], dp[i]);
                }
            }
        }
        int mx = 0;
        for(auto x: dp){
            mx = max(x, mx);
        }
        return mx;
    }
};
