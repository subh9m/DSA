class Solution {
public:
    int findDivisorSum(vector<int>&nums, int limit){
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += ceil((double)(nums[i])/(double)(limit));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high-low)/2;
            int result = findDivisorSum(nums, mid);

            if(result <= threshold){
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        return low;
    }
};