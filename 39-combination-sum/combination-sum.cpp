class Solution {
public:
void func(vector<int> &x1, int i, int sum, vector<int> &l, vector<vector<int>> &ans){
    if(sum == 0) {
        ans.push_back(l);
        return;
    }
    if(i < 0 || sum < 0){
        return;
    }
    func(x1, i - 1, sum, l, ans);
    l.push_back(x1[i]);
    func(x1, i, sum - x1[i], l, ans);
    l.pop_back();

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        func(candidates, candidates.size() - 1, target, list, ans);
        return ans;
    }
};