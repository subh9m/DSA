class Solution {
public:
    int passwordStrength(string password) {
        set<char>st;

        for(int i = 0; i < password.size(); i++){
            st.insert(password[i]);
        }

        int score = 0;
        for(auto it: st){
            if(it >= 'a' && it <= 'z') score += 1;
            if(it >= 'A' && it <= 'Z') score += 2;
            if(it >= '0' && it <= '9') score += 3;
            if(it == '!' || it == '@' || it == '#' || it == '$') score += 5;
        }

        return score;
    }
};