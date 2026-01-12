class Solution {
public:
    int func(int ind, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(ind == 0){
            if(target == 0 && nums[ind] == 0) return 2;

            if(target == 0 || nums[ind] == target) return 1;

            return 0;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        int notPick = func(ind -1, target, nums, dp);
        int pick = 0;

        if(nums[ind] <= target){
            pick = func(ind-1, target - nums[ind], nums, dp);
        }

        return dp[ind][target] = pick + notPick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }

        int diff = totalSum - target;

        if(diff < 0) return 0;

        if(diff % 2 == 1) return 0;

        int s2 = diff / 2;
        vector<vector<int>>dp(n, vector<int>(s2+1, -1));

        return func(n-1, s2, nums, dp);
    }
};