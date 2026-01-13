class Solution {
public:
    int func(int ind, vector<int>&cost, vector<int>&time, int total, vector<vector<int>>&dp){
            if(total <= 0) return 0;
            if(ind < 0) return 1e9;

        if(dp[ind][total] != -1){
            return dp[ind][total];
        }
        int free = 0 + func(ind -1, cost, time, total, dp);
        int paid = cost[ind] + func(ind -1, cost, time, total - time[ind] - 1, dp);
        return dp[ind][total] = min(free, paid);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return func(n-1, cost, time, n, dp);
    }
};