class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>result(2);
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;

        for(auto it:nums1) mpp1[it]++;
        for(auto it:nums2) mpp2[it]++;
        unordered_set<int>st1,st2;
        for(auto it: nums1){
            if(mpp2.find(it) == mpp2.end()){
                st1.insert(it);
            }
        }

        for(auto it: nums2){
            if(mpp1.find(it) == mpp1.end()){
                st2.insert(it);
            }
        }

        return {{vector<int>(st1.begin(), st1.end())}, {vector<int>(st2.begin(), st2.end())}};

    }
};