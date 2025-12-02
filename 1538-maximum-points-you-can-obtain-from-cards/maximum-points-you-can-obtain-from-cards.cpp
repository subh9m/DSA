class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int window = n - k;
        if(window == 0) return total;

        int curr = 0;
        for(int i = 0; i < window; i++){
            curr+= cardPoints[i];
        }

        int minWindow = curr;
        for(int i = window; i < n; i++){
            curr += cardPoints[i] - cardPoints[i-window];
            minWindow = min(curr, minWindow); 
        }

        return total - minWindow;
    }
};