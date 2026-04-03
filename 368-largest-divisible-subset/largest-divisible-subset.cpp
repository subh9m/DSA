class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1);
        int maxLIS = 1;
        int prev_idx = 0;
        vector<int>prev(n, -1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    } 
                    if(dp[i] > maxLIS){
                        maxLIS = dp[i];
                        prev_idx = i;
                    }
                }
            }
        }

        vector<int>ans;

        while(prev_idx != -1){
            ans.push_back(nums[prev_idx]);
            prev_idx = prev[prev_idx];
        }

        return ans;
    }
};