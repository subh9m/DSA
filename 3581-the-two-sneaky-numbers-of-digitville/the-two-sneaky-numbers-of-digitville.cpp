class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(auto it : nums){
            mpp[it]++;
        }

        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(mpp[i] > 1) ans.push_back(i);
        }
        return ans;
    }
};