int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
       
        vector<int>prev(amount+1, -1), curr(amount+1, -1);
        
        for(int target = 0; target<=amount; target++){
            if (target%coins[0]==0)
                prev[target] =  target/coins[0];
            else
                prev[target] = 1e9;
        }
        for(int i=1;i<n;i++){
            for(int target = 0; target<=amount; target++){
                int consider = 1e9, notConsider = 1e9;
                notConsider = 0 + prev[target];
                if(coins[i]<=target)
                    consider = 1 + curr[target-coins[i]];
                curr[target] = min(consider, notConsider);
            }
            prev=curr;
        }
        
        
                
        
        int res = prev[amount];
        if(res==1e9) return -1;
        return res;
    }
