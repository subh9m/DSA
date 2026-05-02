class Solution {
public:
    int rotatedDigits(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {

            int currentNum = i;

            bool flag = false;
            while (currentNum > 0) {
                int currentDigit = currentNum % 10;

                if (!flag && (currentDigit == 2 || currentDigit == 5 ||
                              currentDigit == 6 || currentDigit == 9)) {
                    flag = true;
                }
                if ((currentDigit == 4 || currentDigit == 7 ||
                     currentDigit == 3)) {
                    flag = false;
                    break;
                }
                currentNum /= 10;
            }

            if (flag) {

                result++;
            }
        }
        return result;
    }
};