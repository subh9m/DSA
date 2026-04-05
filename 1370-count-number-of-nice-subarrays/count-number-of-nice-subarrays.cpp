class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mpp;

        mpp[0] = 1;
        int sum = 0;
        int count = 0;

        for(int i = 0; i < n; i++){
            nums[i] = nums[i] % 2;
        }

        for(int i = 0; i < n; i++){
            sum += nums[i];
            int diff = sum - k;

            if(mpp.find(diff) != mpp.end()){
                count += mpp[diff];
            }
            mpp[sum]++;
        }

        return count;
    }
};