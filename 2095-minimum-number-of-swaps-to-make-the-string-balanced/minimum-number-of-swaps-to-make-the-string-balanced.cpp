class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        if(n % 2 != 0) return -1;
        int opening = 0;
        int closing = 0;
        for(int i = 0; i< n; i++) {
            if(s[i] == '[') opening++;
            else{
                if(opening > 0) opening--;
                else closing++;
            }
        }
        int ans = (closing + 1) / 2;
        return ans;
    }
};