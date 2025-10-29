class Solution {
private: 
    void func(int index, int n, vector<int>&list, vector<int>&nums, vector<vector<int>>&ans){
        if(index == n){
            ans.push_back(list);
            return;
        }

        list.push_back(nums[index]);
        func(index + 1, n, list, nums, ans);
        list.pop_back();

        for(int i = index + 1; i < n; i++){
            if(nums[i] != nums[index]){
                func(i, n, list, nums, ans);
                return;
            }
        }
        func(n, n, list, nums, ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int> list;
        sort(nums.begin(), nums.end());

        func(0, n, list, nums, ans);

        return ans;
    }
};