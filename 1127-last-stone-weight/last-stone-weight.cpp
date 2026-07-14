class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>st;


        for(auto it: stones)st.push(it);
        
        while(!st.empty()){
            int a, b;
            if(!st.empty()){
                a = st.top();
                st.pop();
            }
            if(!st.empty()){
                b = st.top();
                st.pop();
                if(a == b)continue;
                else st.push(a-b);
            } else if(st.empty()) return a;
        }


        if(st.empty()) return 0;
        else return st.top();
    }
};