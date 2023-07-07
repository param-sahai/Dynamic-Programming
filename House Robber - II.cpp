class Solution {
public:
    int helper(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>temp1, temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp2.push_back(nums[i]);
            if(i!=nums.size()-1) temp1.push_back(nums[i]);
        }
        
        int op1, op2;
        op1 = helper(temp1), op2 = helper(temp2);
        return max(op1, op2);
        
    }
};
