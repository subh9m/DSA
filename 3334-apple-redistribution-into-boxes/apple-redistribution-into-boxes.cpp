class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();

        sort(capacity.begin(), capacity.end(), greater<int>());

        int sum = accumulate(apple.begin(), apple.end(), 0);

        int count = 0;

        for(int i = 0; i < m; i++){
            if(sum <= 0) break;
            sum -= capacity[i];
            count++;
        }

        return count;
    }
};