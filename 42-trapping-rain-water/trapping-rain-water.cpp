class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left_max(n, 0);
        vector<int>right_max(n, 0);
        //setting two pointers for comparison...
        int curr_left_max = height[0];
        int curr_right_max = height[n-1];

        //calculating left max array...
        for(int i = 0; i < n; i++){
            if(height[i] > curr_left_max){
                left_max[i] = height[i];
                curr_left_max = max(curr_left_max, height[i]);
            } else {
                left_max[i] = curr_left_max;
            }
        }

        //calculating right max array...
        for(int i = n - 1; i >= 0; i--) {
            if(height[i] > curr_right_max){
                right_max[i] = height[i];
                curr_right_max = max(curr_right_max, height[i]);
            } else{
                right_max[i] = curr_right_max;
            }
        }

        int trappedWater = 0;
        for(int i = 0; i < n; i++) {
            int water = min(left_max[i], right_max[i]);
            trappedWater += water - height[i];
        }
        return trappedWater;
    }
};