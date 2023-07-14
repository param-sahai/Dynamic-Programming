#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool>prev(k+1, false);

    // for(int i=0;i<n;i++)
    prev[0] = true;        
    
    if(arr[0]<=k)
    prev[arr[0]] = true;
    
    
    for(int i=1;i<n;i++){
        vector<bool>curr(k+1, false);
        curr[0] = true;
        for(int target = 1; target<=k;target++){
            bool op1 = false, op2 = false;
            //Consider the element
            if(arr[i]<=target)
            op1 = prev[target-arr[i]];
            
            //Skip the element
            op2 = prev[target];

            curr[target] = op1||op2;
        }
        prev = curr;
    }
    return prev[k];

}
