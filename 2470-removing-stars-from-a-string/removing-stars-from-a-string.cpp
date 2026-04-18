class Solution {
public:
    string removeStars(string s) {
        stack<char>st;

        string result = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] != '*'){
                st.push(s[i]);
            } else{
                if(st.empty())continue;
                st.pop();
            }
        }

        while(!st.empty()){
        result.push_back(st.top());
        st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};