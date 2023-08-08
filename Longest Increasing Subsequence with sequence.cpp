class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);
        
        vector<int>hash(nums.size(), 0);
        for(int i=0;i<nums.size();i++) hash[i]=i;
        
            
        int n = nums.size(), mx=0, pos=-1;
        for(int i=0;i<n;i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[prev]<nums[i] && dp[i]<(1+ dp[prev]))
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i]>mx){
                mx = max(dp[i], mx);
                pos = i;
            }
            
        }
        /*
        //Printing length dp
        for(auto x: dp){
            cout<<x<<" ";
        }
        cout<<"\n";
        //Printing hash (position) array
        for(auto x: hash){
            cout<<x<<" ";
            // mx = max(x, mx);
        }
        */
        vector<int>res;
        res.push_back(nums[pos]);
        while(hash[pos]!=pos){
            pos = hash[pos];
            res.push_back(nums[pos]);
        }
        reverse(res.begin(), res.end());
        cout<<"\n";
        for(auto x: res){
            cout<<x<<" ";
        }
        return mx;
    }
};
