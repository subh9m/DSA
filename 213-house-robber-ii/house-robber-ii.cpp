class Solution {
private:
    int getMax(vector<int>&nums, int start, int end){
        int prev = 0;
        int prev2 = 0;

        for(int i = start; i <= end; i++){
            int rob = prev2 + nums[i];
            int skip = prev;
            int curr = max(rob, skip);

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(getMax(nums, 0, n-2), getMax(nums, 1, n-1));
    }
};