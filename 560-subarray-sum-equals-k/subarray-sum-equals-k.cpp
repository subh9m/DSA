class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        mpp[0] = 1;

        int count = 0;
        int current_sum = 0;

        for(int i = 0; i < nums.size(); i++){
            current_sum += nums[i];

            if(mpp.find(current_sum-k) != mpp.end()){
                count += mpp[current_sum-k];
            }
            mpp[current_sum]++;
        }

        return count;
    }
};