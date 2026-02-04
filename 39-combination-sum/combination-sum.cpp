class Solution {
public:
    void func(vector<int>&candidates, vector<int>&sub, vector<vector<int>>&ans, int target, int ind){
        if(target == 0){
            ans.push_back(sub);
            return;
        }
        if(target < 0 || ind < 0) {
            return;
        }

        func(candidates, sub, ans, target, ind - 1);
        sub.push_back(candidates[ind]);
        func(candidates, sub, ans, target - candidates[ind], ind);
        sub.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>sub;
        int n = candidates.size();
        func(candidates, sub, ans, target, n - 1);
        return ans;
    }
};