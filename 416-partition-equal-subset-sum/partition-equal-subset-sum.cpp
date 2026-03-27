class Solution {
public:
    bool func(int index, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(index == nums.size() && target != 0){
            return false;
        }

        if(target == 0)return true;

        if(dp[index][target] != -1)return dp[index][target];

        bool notPick = func(index + 1, target, nums, dp);
        bool pick = false;
        if(nums[index] <= target){
            pick = func(index + 1, target - nums[index], nums, dp);
        }

        return dp[index][target] = (pick || notPick);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it: nums)sum += it;

        if(sum % 2){
            return false;
        } else{
            int k = sum/2;
            vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
            return func(0, k, nums, dp);
        }
    }
};