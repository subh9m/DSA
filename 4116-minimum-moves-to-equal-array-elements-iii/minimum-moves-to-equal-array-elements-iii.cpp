class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_ele = nums[0];
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] > max_ele){
                max_ele = nums[i];
            }
        }
        int result = 0;

        for(int i = 0; i < n; i++){
            result += max_ele - nums[i]; 
        }
        return result;
    }
};