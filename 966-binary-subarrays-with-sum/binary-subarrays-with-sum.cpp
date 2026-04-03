class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        mpp[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int diff = sum - goal;
            if(mpp.find(diff) != mpp.end()){
                count += mpp[diff];
            }

            mpp[sum]++;
        }

        return count;
    }
};