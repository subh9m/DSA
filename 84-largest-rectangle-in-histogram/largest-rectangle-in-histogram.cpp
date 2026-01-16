class Solution {
public:
    vector<int>nextSmallerElement(vector<int>&heights){
        int n = heights.size();
        vector<int>nse(n, n);
        stack<int>st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            nse[i] = st.empty()? n: st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>previousSmallerElement(vector<int>&heights){
        int n = heights.size();
        vector<int>pse(n, -1);
        stack<int>st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            pse[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return pse; 
    }


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nextSmallerArray = nextSmallerElement(heights);
        vector<int>previousSmallerArray = previousSmallerElement(heights);
        int maxHeight = 0;

        for(int i = 0; i < n; i++){
            int currHeight = (nextSmallerArray[i] - previousSmallerArray[i] - 1)*heights[i];
            maxHeight = max(maxHeight, currHeight);
        }

        return maxHeight;

        
    }
};