class Solution {
public:
    int trailingZeroes(int n) {
        int countFives = 0;

        while(n > 0){
            n /= 5;
            countFives += n; 
        }

        return countFives;
    }
};