class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin(), piles.end());
        int num = piles.size() / 3;
        int coins = 0;
        int i = piles.size() - 2;
        while(num){
            coins += piles[i];
            cout<<"you got "<<piles[i]<<" ";
            i = i - 2;
            num--;
        }

        return coins;
    }
};