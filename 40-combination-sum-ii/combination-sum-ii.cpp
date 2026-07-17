class Solution {
public:
    vector<vector<int>>result;
    vector<int>combo;

    void backtrack(vector<int>& candidates, int target, int ind){
        if(target == 0){
            result.push_back(combo);
            return;
        }

        if(target < 0) return;

        for(int i = ind; i < candidates.size(); ++i){
            if(candidates[i] > target) break;

            if(i > ind && candidates[i] == candidates[i-1]) continue;

            combo.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i+1);
            combo.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return result;
    }
};