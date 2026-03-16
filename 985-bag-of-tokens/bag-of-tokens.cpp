class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i = 0;
        int j = n-1;
        int score = 0;
        int maxScore = 0;
        while(i <= j){
            if(tokens[i] <= power){
                score++;
                maxScore = max(score, maxScore);
                power -= tokens[i];
                i++;
                continue;
            } else if(score != 0){
                score--;
                maxScore = max(score, maxScore);
                power += tokens[j];
                j--;
            } else break;
        }
        return maxScore;
    }
};