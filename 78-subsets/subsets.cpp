class Solution {
public:
    void func(int ind, vector<int>&temp, vector<vector<int>>&ans, vector<int>&nums){
        if(ind < 0){
            ans.push_back(temp);
            return;
        }
        func(ind - 1, temp, ans, nums);
        temp.push_back(nums[ind]);        
        func(ind -1 , temp, ans, nums);
        temp.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        if(n == 0) return ans;
        vector<int>temp;
        func(n-1, temp, ans, nums);
        return ans;
    }
};