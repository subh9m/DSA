class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int r = n - 1;
        int l = 0;
        int maxArea = 0;
        while(l < r){
            int minn = min(height[r], height[l]);
            int currArea = minn * (r - l);
            maxArea = max(currArea, maxArea);
            if(height[l] < height[r]){
                l++;
            }
            else r--;
        }
        return maxArea;
        
    }
};