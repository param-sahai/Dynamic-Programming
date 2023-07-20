class Solution {
public:
//MEMOIZATION
// int helper(int i, int value, int *coins, vector<vector<int>>&dp){
//     //Base Conditions
//     if(i==0)
//         if(value%coins[i]==0) return 1;
//         else return 0;
//     if(dp[i][value]!=-1) return dp[i][value];
//     //Choose NotChoose
//     int choose = 0, notChoose = 0;
//     notChoose = helper(i-1, value, coins, dp);

//     if(coins[i]<=value)
//     choose = helper(i, value-coins[i], coins, dp);

//     return dp[i][value] = choose+notChoose;
// }

// //Tabulation
// int countWaysToMakeChange(int *coins, int n, int value)
// {
//     //Write your code here
//     vector<vector<int>>dp(n, vector<int>(value+1, 0));
//     // return helper(n-1, value, coins, dp);

//     for(int i=0;i<=value;i++){
//         if(i%coins[0]==0)
//             dp[0][i]=1;
//         // Else condition is automatically fulfilled,
//         // as dp array is initialized to zero
//     }

//     for(int i=1;i<n;i++){
//         for(int val = 0; val<=value; val++){
//             int choose = 0, notChoose = 0;
//             notChoose = dp[i-1][val];

//             if(coins[i]<=val)
//             choose = dp[i][val-coins[i]];

//             dp[i][val] = choose+notChoose;
//         }
//     }

//     return dp[n-1][value];
// }


//SPACE OPTIMIZATION
int change(int value, vector<int>&coins)
{
    int n = coins.size();

    vector<int>prev(value+1, 0);
    vector<int>curr(value+1, 0);


    for(int i=0;i<=value;i++){
        if(i%coins[0]==0)
            prev[i]=1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }

    for(int i=1;i<n;i++){
        for(int val = 0; val<=value; val++){
            int choose = 0, notChoose = 0;
            notChoose = prev[val];

            if(coins[i]<=val)
            choose = curr[val-coins[i]];

            curr[val] = choose+notChoose;
        }
        prev = curr;
    }

    return prev[value];
}
};
