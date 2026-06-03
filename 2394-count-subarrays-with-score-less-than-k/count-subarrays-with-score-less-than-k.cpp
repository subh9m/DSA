class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        long long ans = 0;

        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];

            while(sum * (r-l+1LL) >= k){
                sum -= nums[l];
                l++;
            }

            ans += (r - l + 1ll);
        }
        return ans;

    }
};