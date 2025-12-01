class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for(const auto& s: strs){
            string str = s;
            sort(str.begin(), str.end());
            mpp[str].push_back(s);
        }

        vector<vector<string>>ans;
        for(auto& pair: mpp){
            ans.push_back(pair.second);
        }

        return ans;
    }
};