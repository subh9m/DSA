class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for(auto num: nums){
            if(num % 3 != 0) ops++;
        }
        return ops;
    }
};