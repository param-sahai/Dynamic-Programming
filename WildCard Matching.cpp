class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        vector<bool>prev(m+1, false), curr(m+1, false);
        //Space Optimization
        
        //Base Case
        prev[0] = true;
        
        for(int j=1;j<=m;j++){
            bool flag = true;
            int k = j;
            while(k-1>=0){
                if(p[k-1]!='*'){
                    flag = false;
                    break;
                } 
                k--;
            }
            prev[j] = flag;
        }
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){ 
                if(s[i-1]==p[j-1]||p[j-1]=='?')
                    curr[j] = prev[j-1];
                else if(p[j-1]=='*')
                {
                    bool op1=false, op2=false;
                    //Empty sequence
                    op1 = curr[j-1];

                    //sequence
                    op2 = prev[j];

                    curr[j] = op1 || op2;
                }
                else
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
        
        
    }
};
