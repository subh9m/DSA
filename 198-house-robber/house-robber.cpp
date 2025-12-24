class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return nums[0];

        int prev2 = 0;
        int prev = 0;

        for(int i = 0;  i < n; i++){
            int rob = prev2 + nums[i];
            int skip = prev;

            int curr = max(rob, skip);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};