class Solution {
public:
    const long long MOD = 1e9+7;

    long long mypow(long long base, long long exp){
        long long res = 1;
        base %= MOD;
        while(exp > 0){
            if(exp % 2 == 1){
                res = (res * base)%MOD;
            }
            base = (base*base)%MOD;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n+1)/2;
        long long oddCount = n/2;

        long long result = (mypow(5, evenCount)* mypow(4, oddCount))%MOD;
        return result;
    }
};