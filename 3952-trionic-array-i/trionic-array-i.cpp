class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool cond1 = false;
        bool cond2 = false;
        bool cond3 = false;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) return false;
            if(!cond1 && !cond2 && !cond3){
                if(nums[i] < nums[i-1]) return false;
            }

            if(cond1 && cond2 && cond3){
                if(nums[i] < nums[i-1]) return false;
            }

            if(nums[i] > nums[i-1]){
                cond1 = true;
            }

            if(cond1 && nums[i] < nums[i-1]){
                cond2 = true;
            }

            if(cond1 && cond2 && nums[i] > nums[i-1]){
                cond3 = true;
            } 
        }

        if(cond1 && cond2 && cond3) return true;
        return false;
    }
};