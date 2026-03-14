class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans;

        int i = 0;
        int j = 0;

        int l1 = firstList.size();
        int l2 = secondList.size();

        while(i < l1 && j < l2){
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            int st = max(start1, start2);
            int en = min(end1, end2);
            if(st <= en){
                ans.push_back({st, en});
            }
            if(firstList[i][1] < secondList[j][1]){
                i++;
            } else{
                j++;
            }
        }
        return ans;
        
    }
};