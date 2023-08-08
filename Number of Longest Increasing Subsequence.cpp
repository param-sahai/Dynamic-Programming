class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);
        
        vector<int>count(nums.size(), 1);
       
            
        int n = nums.size(), mx=0, pos=-1;
        for(int i=0;i<n;i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[prev]<nums[i] && dp[i]<(1+ dp[prev]))
                {
                    dp[i] = 1 + dp[prev];
                    count[i] = count[prev];
                }
                else if(nums[prev]<nums[i] && dp[i]==(1+ dp[prev]))
                {
                    count[i] += count[prev];
                }
            }
            mx = max(dp[i], mx);  
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(dp[i]==mx)
                cnt+=count[i];
        }
        return cnt;
    }
};
