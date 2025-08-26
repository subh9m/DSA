class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        stringstream ss(s);
        string word;
        stack<string>st;
        char delimiter = ' ';
         while (getline(ss, word, delimiter)) {
            if(!word.empty()){
                st.push(word); 
            }           
        }
        while(!st.empty()){
            char space = ' ';
            ans+=st.top();
            st.pop();
            if(!st.empty()){
                ans+=space;
            }
        }

        return ans;
    }
};