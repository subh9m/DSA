class Solution {
public:
    string reverseByType(string s) {
        string ans = "";
        string alpha = "";
        string chara = "";

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])) alpha+=s[i];
            else chara += s[i];
        }

        int j = 0, k = 0;
        reverse(alpha.begin(), alpha.end());
        reverse(chara.begin(), chara.end());

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])) ans+=alpha[j++];
            else ans+=chara[k++];
        }

        return ans;
    }
};