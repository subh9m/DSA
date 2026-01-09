class Solution {
public:
    int func(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(ind == 0){
            if(amount % coins[ind] == 0){
                return amount / coins[ind];
            } else return 1e9;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notPick = 0 + func(ind - 1, amount, coins, dp);

        int pick = 1e9;
        if(coins[ind] <= amount){
            pick = 1 + func(ind, amount - coins[ind], coins, dp);
        }
        return dp[ind][amount] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>>dp(n, vector<int>(amount+1, -1));

        int ans = func(n-1, amount, coins, dp);

        if(ans >= 1e9) return -1;
        return ans;
    }
};