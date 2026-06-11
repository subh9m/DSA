class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int counter = 0;
        for(int i = 0; i < size; i++){
            if(flowerbed[i] == 1) continue;

            int left = (i == 0)? 0:flowerbed[i-1];
            int right = (i == size-1)? 0 : flowerbed[i+1];

            if(left == 0 && right == 0){
                flowerbed[i] = 1;
                counter++;
            }

            if(counter >= n) return true;
        }

        return counter >= n;
    }
};