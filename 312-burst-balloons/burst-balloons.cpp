class Solution {
public:
    int func(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i > j)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int maxi = INT_MIN;

        for(int ind = i; ind <= j; ind++){
            int coins = nums[i-1] * nums[ind] * nums[j+1] + func(i, ind-1, nums, dp) 
                        + func(ind+1, j, nums, dp);
            maxi = max(coins, maxi);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int c = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>>dp(c+1, vector<int>(c+1, -1));
        return func(1, c, nums, dp);
    }
};