class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n+1, 0);

        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(prefix[j+1] - prefix[i] == k) count++;
            }
        }

        return count;
    }
};