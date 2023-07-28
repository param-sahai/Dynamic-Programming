class Solution {
public:
   int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m=text2.size();
        vector<int>prev(m+1, 0);
        vector<int>curr(m+1, 0);
        for(int j=0;j<=m;j++){
                prev[j] = 0;
        }
                
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1]) //Pick
                    curr[ind2] = 1 + prev[ind2-1];
                else
                    curr[ind2] = 0 + max(prev[ind2] , curr[ind2-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};
