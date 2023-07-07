#include<bits/stdc++.h>
int helper(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(dp[day][last]!=-1) return dp[day][last];

    int maxi = INT_MIN;
    if(day==0){ //base case
        for (int task = 0; task < 3; task++) {
          if (task != last)
            maxi = max(maxi, points[day][task]);
        }
        return dp[day][last]=maxi;
    }

    // int maxi = INT_MIN;
    for(int task=0; task<3; task++){
        if(task!=last){
            int point = points[day][task] + helper(day-1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}



int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector < int > prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {

    vector < int > temp(4, 0);
    for (int last = 0; last < 4; last++) {
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }

    prev = temp;

  }

  return prev[3];

}
