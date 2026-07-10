class Solution {
public:
    int sumBase(int n, int k) {
        int sumDigit = 0;

        while(n > 0){
            sumDigit += (n%k);
            n /= k;
        }

        return sumDigit;
    }
};