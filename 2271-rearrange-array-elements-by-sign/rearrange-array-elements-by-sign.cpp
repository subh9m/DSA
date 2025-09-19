class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positives;
        vector<int> negatives;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                negatives.push_back(nums[i]);
            }
            else {
                positives.push_back(nums[i]);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n/2; i++){
            ans.push_back(positives[i]);
            ans.push_back(negatives[i]);
        }
        return ans;
    }
};