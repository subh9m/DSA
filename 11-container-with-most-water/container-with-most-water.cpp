class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0; 
        int r = n-1;

        int maxWater = INT_MIN;
        int area = 0;
        while(l < r){
            area = (min(height[l], height[r]))*(r-l);
            maxWater = max(area, maxWater);

            if(height[l] < height[r]){
                l++;
            } else{
                r--;
            }
        }

        return maxWater;
        
    }
};