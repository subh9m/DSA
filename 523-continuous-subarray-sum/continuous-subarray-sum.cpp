class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int>mpp;
        mpp[0] = -1;
        int currentSum = 0;
        for(int i = 0; i < n; i++){
            currentSum += nums[i];
            int diff = currentSum % k;
            if(mpp.find(diff) != mpp.end()){
                if(i - mpp[diff] > 1) return true;
            }else{
                mpp[diff] = i;
            }
        }
        return false;
    }
};