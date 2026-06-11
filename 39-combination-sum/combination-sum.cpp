class Solution {
public:
    void func(int ind, int target, vector<int>&candidates, vector<vector<int>>&result, vector<int>&subSet) {
        if(ind == -1){
            if(target == 0){
                result.push_back(subSet);
                return;
            }
            return;
        }

        if(target == 0){
            result.push_back(subSet);
            return;
        }

        //take
        if(candidates[ind] <= target) {
            subSet.push_back(candidates[ind]);
            func(ind, target - candidates[ind], candidates, result, subSet);
            subSet.pop_back();            
        } 
        func(ind - 1, target, candidates, result, subSet);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>subSet;
        int n = candidates.size();

        func(n-1, target, candidates, result, subSet);

        return result;
    }
};