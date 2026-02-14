class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(int i = 0; i < tokens.size(); i++){

            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
            

            if(tokens[i] == "+"){
                st.push(first + second);
            }

            if(tokens[i] == "-"){
                st.push(first - second);
            }

            if(tokens[i] == "*"){
                st.push(first * second);
            }

            if(tokens[i] == "/"){
                st.push(first / second);
            }
            }

            else st.push(stoi(tokens[i]));

        }

        return st.top();
    }
};