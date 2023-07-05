int rob(vector<int>& nums) {
        int prev1 = nums[0], prev2 = nums[0], curr=-1;
        for(int i=1;i<nums.size();i++){
            int select = INT_MIN, notSelect;
            if(i==1)
                select = nums[i]; 
            else if(i>1)
                select = nums[i] + prev2;
            notSelect = 0 + prev1;
            
            curr = max(select, notSelect);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
