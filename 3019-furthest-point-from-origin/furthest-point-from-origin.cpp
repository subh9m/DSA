class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int L = 0;
        int R = 0;
        int D = 0;
        for(auto it: moves){
            if(it == 'L')L++;
            if(it == 'R')R++;
            if(it == '_')D++;
        }

        int diff = abs(L-R);
        return D+diff;
    }
};