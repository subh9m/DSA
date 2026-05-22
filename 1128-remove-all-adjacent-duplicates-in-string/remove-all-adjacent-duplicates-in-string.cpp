class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0;
        int n = s.size();
        stack<char>st;
        while(i < n){
            if(st.empty() || st.top() != s[i]){
                st.push(s[i]);
                i++;
            }else{
                while(!st.empty() && st.top() == s[i]){
                    st.pop();
                }
                i++;
            }

        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};