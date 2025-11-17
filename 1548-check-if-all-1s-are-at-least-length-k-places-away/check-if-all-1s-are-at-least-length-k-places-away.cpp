class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int counter = k;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                counter++;
            }
            else{
                if(counter < k && i != 0) return false;
                counter = 0;
            }
        }
        return true;
    }
};