class Solution {
public:
    unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    string reverseVowels(string s) {
        int n = s.size();
        int j = n - 1;
        int i = 0;
        while(i < j){
            if(st.count(s[i]) && st.count(s[j]) ){
                swap(s[i], s[j]);
                j--;
                i++;
            }

            if(!st.count(s[j])){
                j--;
            }

            if(!st.count(s[i])){
                i++;
            }
        }

        
        return s;
    }
};