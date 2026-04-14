class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int counter = 0;

        for(char ch: s){
            if(ch == '('){
                if(counter > 0)result += ch;
                counter++;
            }else{
                counter--;
                if(counter > 0)result += ch;
            }
        }
        return result;
    }
};