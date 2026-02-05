class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>ans(n, 0);
        for(int i = 0; i < nums.size(); i++){
            int shift = nums[i] % n;

            int newInd = (i + shift) % n;
           
            if(newInd < 0){
                newInd += n;
            }
            ans[i] = nums[newInd];
        }

        return ans;
    }
};