class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        vector<bool> inStack(26, false);

        for(char c : s){
            freq[c - 'a']++;
        }
        stack<char>st;

        for(char c: s){
            freq[c - 'a']--;
            if(inStack[c-'a']) continue;
            while(!st.empty() && st.top() > c && freq[st.top() - 'a'] >0) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            inStack[c - 'a'] = true;
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};