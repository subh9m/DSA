class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int, int>mpp;

        for(auto it: nums)mpp[it]++;

        int x = k;
        vector<int>ans;

        for(auto it: mpp){
            int val = it.second;
            if(it.second <= k){
                while(it.second != 0){
                    ans.push_back(it.first);
                    it.second--;
                }
            }else{
            while(it.second != val - k){
                ans.push_back(it.first);
                it.second--;
            }
            }
        }

        return ans;
    }
};