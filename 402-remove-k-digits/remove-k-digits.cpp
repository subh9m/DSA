class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        for(char c: num){
            while(!st.empty() && k > 0 && st.top() > c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int index = 0;
        while(index < ans.size() && ans[index] == '0') index++;
        ans = ans.substr(index);

        return ans.empty() ?"0" :ans;
    }
};