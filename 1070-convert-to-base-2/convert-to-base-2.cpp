class Solution {
public:
    string baseNeg2(int n) {
        
        string ans = "";
        if(n == 0) return ans + "0";
        while(n != 0){
            int quotient = n / -2;
            int remainder = n % -2;
            if(remainder < 0) {
                remainder += 2;
                quotient += 1;
            }
            n = quotient;
            ans += to_string(remainder);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};