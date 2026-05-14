class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        bool ans = true;
        for(int i = 1; i <= n; i++){
            if(nums[i-1] != i && i < n){
                ans = false;
                break;
            }else if(i == n && nums[i-1] != i-1){
                ans = false;
                break;
            }
        }
        return ans;
    }
};