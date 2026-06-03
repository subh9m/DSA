class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long product = 1;
        long long ans = 0;

        int l = 0;

        if(k <= 1)return 0;
        for(int r = 0; r < nums.size(); r++){
            product *= nums[r];

            while(product >= k){
                product /= nums[l];
                l++;
            }
            ans += (r-l+1ll);
        }
        return ans;
    }
};