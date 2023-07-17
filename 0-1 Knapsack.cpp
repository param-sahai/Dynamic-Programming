#include <bits/stdc++.h> 
int helper(int i, int W, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
	if(i==0) return (W>=weight[0] ? value[i] : 0);
	if(W<=0) return 0;

	if(dp[i][W]!=-1) return dp[i][W];

	int consider=0, notConsider=0;
	notConsider = 0 + helper(i-1, W, weight, value, dp);
	if(weight[i]<=W)
	consider = value[i] + helper(i-1, W-weight[i], weight, value, dp);
	
	return dp[i][W] = max(consider, notConsider);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// vector<vector<int>>dp(n, vector<int>(maxWeight+1, 0));
	// return helper(n-1, maxWeight, weight, value, dp);
	vector<int>prev(maxWeight+1, 0);
	for(int i=weight[0];i<=maxWeight;i++){
		prev[i]  = value[0];
	}

	for(int i=1;i<n;i++){
		for(int W=maxWeight;W>=0;W--){
			int consider=0, notConsider=0;
			notConsider = 0 + prev[W];
			if(weight[i]<=W)
			consider = value[i] + prev[W-weight[i]];

			prev[W] = max(consider, notConsider);
		}
	}
	return prev[maxWeight];
	
}
