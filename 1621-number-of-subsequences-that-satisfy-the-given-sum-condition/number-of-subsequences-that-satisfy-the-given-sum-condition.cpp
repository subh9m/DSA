class Solution {
public:
    int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        vector<long long>computed(n, 1);

        for(int i = 1; i < n; i++){
            computed[i] = 2 * computed[i-1] % MOD;
        }

        sort(nums.begin(), nums.end());

        int l = 0;
        int r = n - 1;
        long long ans = 0;
        while(l <= r){
            if(nums[r] + nums[l] <= target){
                ans = ((ans % MOD) + computed[r-l] % MOD) % MOD;
                l++;
            } else r--;
        }

        return ans % MOD;
    }
};