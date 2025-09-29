class Solution {
public:
    void generateSubsets(int index, int n, vector<int>&list, vector<vector<int>>&ans, vector<int>&nums){
        if(index == n){
            ans.push_back(list);
            return;
        }
        generateSubsets(index+1, n, list, ans, nums);
        list.push_back(nums[index]);
        generateSubsets(index + 1, n, list, ans, nums);
        list.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int> list;
        generateSubsets(0, n, list, ans, nums);
        return ans;
    }
};