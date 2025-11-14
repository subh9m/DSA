class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int left_max = 0;
        int right_max = 0;
        int trapped_water = 0;

        while(left < right) {
            if(height[left] > height[right]){
                if(height[right] >= right_max){
                    right_max = height[right];
                } else{
                    trapped_water += right_max - height[right];
                }
                right--;
            } else {
                if(height[left] >= left_max){
                    left_max = height[left];
                } else{
                    trapped_water += left_max - height[left];
                }
                left++;
            }
        }

        return trapped_water;
        
    }
};