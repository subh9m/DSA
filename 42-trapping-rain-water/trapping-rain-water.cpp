class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        //two pointers left and right...
        int left = 0;
        int right = n - 1;
        int left_max = 0, right_max = 0;
        int trappedWater = 0;
        
        while(left < right) {
            if(height[left] > height[right]){
                if(height[right] >= right_max){
                    right_max = height[right];
                } else{
                    trappedWater += right_max - height[right];
                }
                right--;
            } else{
                if(height[left] >= left_max){
                    left_max = height[left];
                } else{
                    trappedWater += left_max - height[left];
                }
                left++;
            }
        }

        return trappedWater;
    }
};