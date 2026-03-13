class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        if(n == 1) return 1;

        int i = 0;
        int j = n-1;
        int count = 0;
        sort(people.begin(), people.end());

        while(i < j){
            if(people[i] + people[j] <= limit){
                count++;
                i++;
                j--;
                if(i == j)count++;
            }else{
                count++;
                j--;
                if(i == j)count++;
            }
        }
        return count;
    }
};