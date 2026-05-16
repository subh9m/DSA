class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff(n, 0);

        for(auto it: queries){
            int start = it[0];
            int end = it[1];

            diff[start] -= 1;

            if(end+1 < n){
                diff[end+1] += 1;
            }
        }

        for(int i = 1; i < n; i++){
            diff[i] += diff[i-1];
        }
        for(auto it: diff)cout<<it<<" ";

        for(int i = 0; i < n; i++){
            if(nums[i] + diff[i] > 0)return false;
        }

        return true;
    }
};