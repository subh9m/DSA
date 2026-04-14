class Solution {
public:
    int func(vector<int>&weights, int days, int capacity){
        int days_used = 1;
        int current_load = 0;

        for(int w: weights){
            if(current_load + w > capacity){
                days_used++;
                current_load = w;
            }else{
                current_load += w;
            }
        }
        return (days_used <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(func(weights, days, mid)){
                high = mid -1;
                ans = mid;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }
};