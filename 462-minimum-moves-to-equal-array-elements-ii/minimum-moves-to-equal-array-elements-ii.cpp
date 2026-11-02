class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = 0;
        int mid = n/2;

        for(int i = 0; i < n; i++){
            result += abs(nums[i] - nums[mid]);
        }
        return result;
    }
};