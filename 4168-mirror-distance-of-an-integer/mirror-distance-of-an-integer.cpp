class Solution {
public:
    int mirrorDistance(int n) {
        if(n < 10)return 0;

        int reverseNum = 0;
        int currentNum = n;

        while(currentNum > 0){
            int currentDigit = currentNum%10;
            reverseNum = reverseNum*10 + currentDigit;
            currentNum /= 10;
        }

        return (abs(n - reverseNum));
    }
};