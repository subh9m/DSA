class Solution {
public:
    long func(int ind, int buy, int fee, int n, vector<int>&prices, vector<vector<int>>&dp){
        if(ind == n)return 0;

        long profit = 0;
        if(dp[ind][buy] != -1)return dp[ind][buy];

        if(buy == 0){
            profit = max(0 + func(ind+1, 0, fee, n, prices, dp),
                       (-1)*prices[ind] + func(ind+1, 1, fee, n, prices, dp));
        }else{
            profit = max(0 + func(ind+1, 1, fee, n, prices, dp),
                        prices[ind] - fee + func(ind +1, 0, fee, n, prices, dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        if(n == 0) return 0;
        vector<vector<int>>dp(n, vector<int>(3, -1));

        return func(0, 0, fee, n, prices, dp);
    }
};