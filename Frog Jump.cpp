#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    int curr, prev=0, prev2=0;
    for(int i=1;i<n;i++){
        int fs, ss = INT_MAX;
        fs = prev + abs(heights[i] - heights[i-1]);
        if(i>1)
        ss = prev2 + abs(heights[i] - heights[i-2]);
        curr = min(fs, ss);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
