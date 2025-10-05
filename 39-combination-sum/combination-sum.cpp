class Solution {
public:
    void func(vector<int>& candidates, int index, int target, vector<int> &sub, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(sub);
            return;
        }
        if(target < 0 || index < 0){
            return;
        }

        func(candidates, index - 1, target, sub, ans);
        sub.push_back(candidates[index]);
        func(candidates, index, target - candidates[index], sub, ans);
        sub.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> sub;
        int n = candidates.size();

        func(candidates, n - 1, target, sub, ans);
        return ans;
    }
};