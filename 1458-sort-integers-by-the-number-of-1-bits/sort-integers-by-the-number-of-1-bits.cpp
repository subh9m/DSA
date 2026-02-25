class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>>tmp(32);
        vector<int>ans;

        for(int i = 0; i < arr.size(); i++){
            int a = __builtin_popcount(arr[i]);
            tmp[a].push_back(arr[i]);
        }

        for(auto &it: tmp){
            sort(it.begin(), it.end());
        }

        for(auto &it: tmp){
            for(auto &iter: it){
                ans.push_back(iter);
            }
        }
        return ans;
    }
};