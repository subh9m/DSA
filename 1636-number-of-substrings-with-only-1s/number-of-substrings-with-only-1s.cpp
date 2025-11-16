class Solution {
public:
    const int mod = 1e9 + 7;
    int numSub(string s) {
        long long n = 0;
        long long ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                n++;
                ans += n;
            } else n = 0;
        }
         
        return ans % mod;
        
    }
};