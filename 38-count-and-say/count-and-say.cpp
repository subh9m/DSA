class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prev = countAndSay(n - 1);
        int count = 1;
        string res = "";
        int i = 1;
        for(i; i< prev.size(); i++){
            if(prev[i] == prev[i - 1]){
                count++;
            }
            else{
                res += ('0' + count);
                res += prev[i-1];
                count = 1;
            }
        }
        res += ('0' + count);
        res += prev[i - 1];
        return res;
        
    }
};