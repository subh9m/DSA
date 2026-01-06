class Solution {
public:
    bool func(int ind, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(target == 0) return true;

        if(ind == 0){
            return nums[ind] == target;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        bool notTaken = func(ind-1, target, nums, dp);
        bool taken = false;
        if(nums[ind] <= target){
            taken = func(ind-1, target - nums[ind], nums, dp);
        }
        return dp[ind][target] = taken || notTaken;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2){
            return false;
        } else{
            int k = sum / 2;
            vector<vector<int>>dp(n, vector<int>(sum+1, -1));
            return func(n-1, k, nums, dp);
        }
    }
};