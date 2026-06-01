class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());

        int minCost = 0;
        int i = n-1;

        if(n < 3){
            int sum = 0;
            for(auto it: cost) sum += it;

            return sum;
        }

        while(i >= 0){
            if(i <= 1){
                int sum = 0;
                for(int j = 0; j <= i; j++)sum += cost[j];

                minCost += sum;  
                break;
            }
            int x = cost[i--];
            int y = cost[i--];
            int z = cost[i--];
            minCost += (x + y);
        }

        return minCost;

    }
};