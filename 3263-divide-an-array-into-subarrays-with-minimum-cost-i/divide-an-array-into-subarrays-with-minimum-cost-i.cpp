class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum = nums[0];
        int temp = INT_MAX;
        for(int i = 1; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                temp = min(temp, nums[i] +  nums[j]);
            }
        }

        return sum + temp;
    }
};