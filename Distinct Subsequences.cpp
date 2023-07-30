//https://leetcode.com/problems/distinct-subsequences/discuss/3840078/4-Approaches-oror-step-by-step-oror-Recursion-greater-Memoization-greater-Tabulation-greater-Space-Optimization
Approach 1: Recursion (TLE)
T.C = O(Exponential)
S.C = O(N + M)


//helper function return the number of distinct sub. of s[0...i] which equals t[0...j]
    int helper(int i, int j, string &s, string &t){
        //Base conditions
        if(j<0) return 1;
        if(i<0) return 0;
        
        else if(s[i]==t[j]){
            return (helper(i-1, j-1, s, t) + helper(i-1, j, s, t));
        }
        else
            return helper(i-1, j, s, t); 
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        return helper(n-1, m-1, s, t);
    }


Approach 2: Memoization (Accepted)
T.C = O(N X M)
S.C = O(N + M) + O(N X M) [DP]


int helper(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        //Base conditions
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        else if(s[i]==t[j]){
            return dp[i][j] = (helper(i-1, j-1, s, t, dp) + helper(i-1, j, s, t, dp));
        }
        else
            return dp[i][j] = helper(i-1, j, s, t, dp); 
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return helper(n-1, m-1, s, t, dp);
    }



Approach 3: Tabulation (Accepted)
T.C = O(N X M)
S.C = O(N X M)


#define mod 1000000000
int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<ll>>dp(n+1, vector<ll>(m+1, 0)); 
		//Note the change in dp array size here. It is done to handle the base cases.
          
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
                else
                    dp[i][j] = (dp[i-1][j])%mod;
            }
        }
        return dp[n][m];
    }


Approach 4: Space Optimzation (Accepted)
T.C = O(N X M)
S.C = O(M + M)  ≈ O(M)


int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int>prev(m+1, 0), curr(m+1, 0);
        prev[0]  = curr[0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    curr[j] = (prev[j-1] + prev[j])%mod;
                else
                    curr[j] = (prev[j])%mod;
            }
            prev = curr;
        }
        return prev[m];      
    }



BONUS
Approach 5: Space Optimization 2.0
T.C = O(N X Ml)
S.C = O(M) [1-d dp]


int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int>dp(m+1, 0);
        dp[0]=1;
                
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1])
                    dp[j] = (dp[j-1] + dp[j])%mod;
                else
                    dp[j] = (dp[j])%mod;
            }
        }
        return dp[m];
       }
