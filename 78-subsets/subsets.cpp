class Solution {
private: 
            void findSum(int index, int n, vector<int>&list, vector<int>&nums,
                        vector<vector<int>>&ans){
                    if(index == n){
                        ans.push_back(list);
                        return;
                    }

                    findSum(index + 1, n, list, nums, ans);
                    list.push_back(nums[index]);
                    findSum(index + 1, n, list, nums, ans);
                    list.pop_back();
        }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int> list;

        findSum(0, n, list, nums, ans);

        return ans;
    }
};