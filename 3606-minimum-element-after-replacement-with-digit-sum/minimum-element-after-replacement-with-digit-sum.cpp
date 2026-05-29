class Solution {
public:
    int minElement(vector<int>& nums) {
        int minEle = INT_MAX;

        for(auto it: nums){
            int num = it;
            int sum = 0;

            while(num > 0){
                sum += (num % 10);
                num /= 10;
            }
            minEle = min(sum, minEle);
        }
        return minEle;
    }
};