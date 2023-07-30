class Solution {
    #define mod 1000000000
public:
    int helper(int i, int j, string &word1, string &word2, vector<vector<int>>&dp){
        //Base Case
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        
        if(dp[i][j]!=-1) return dp[i][j];
        int op1, op2, op3, op4 = INT_MAX;
        //Insertion
        op1 = 1 + (helper(i, j-1, word1, word2, dp) % mod);
        
        //Deletion
        op2 = 1 + (helper(i-1, j, word1, word2, dp)%mod);
        
        //Replace
        op3 = 1 + (helper(i-1, j-1, word1, word2, dp)%mod);
        
        //Skip if characters are same
        if(word1[i]==word2[j])
        op4 = (helper(i-1, j-1, word1, word2, dp)%mod);
        
        
        return dp[i][j] = min(op1, min(op2, min(op3, op4)));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        // return helper(n-1, m-1, word1, word2, dp);
        vector<int>prev(m+1, 0), curr(m+1, 0);
        
        //Base
           
        for(int j=0;j<=m;j++){
            prev[j]  = j;
        }
        
        
        
        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){
                int op1, op2, op3, op4 = INT_MAX;
                //Insertion
                op1 = 1 + curr[j-1];

                //Deletion
                op2 = 1 + prev[j];

                //Replace
                op3 = 1 + prev[j-1];

                //Skip if characters are same
                if(word1[i-1]==word2[j-1])
                op4 = prev[j-1];
                
                curr[j] = min(op1, min(op2, min(op3, op4)));
            }
            prev = curr;
        }
        return prev[m];
        
    }
};
