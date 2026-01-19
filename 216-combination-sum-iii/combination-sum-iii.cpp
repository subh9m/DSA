class Solution {
public:
    void func(int last, int sum, int k, vector<int>&nums, vector<vector<int>>&ans){
        if(sum == 0 && nums.size() == k){
            ans.push_back(nums);
            return;
        }
        if(sum <= 0 || nums.size() > k)return;

        for(int i = last; i <= 9; i++){
            if(i <= sum){
                nums.push_back(i);
                func(i+1, sum - i, k, nums, ans);
                nums.pop_back();
            }else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>nums;
        func(1, n, k, nums, ans);
        return ans;
    }
};