class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int runningSum = 0;
        for(int i = 0; i < n; i++){
            if(runningSum == sum - runningSum - nums[i]){
                return i;
            }
            runningSum += nums[i];
        }

        return -1;
    }
};