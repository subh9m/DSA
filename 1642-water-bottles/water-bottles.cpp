class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalBottles = numBottles;

        while(numBottles >= numExchange){
            int bottles = numBottles / numExchange;
            totalBottles += bottles;
            numBottles %= numExchange;
            numBottles += bottles;
        }
        return totalBottles;
    }
};