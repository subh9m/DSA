class Solution {
public:
    void solve(vector<char>& s, int idx, int limit){
        if(idx >= limit) return;
        solve(s, idx + 1, limit - 1);
        swap(s[idx], s[limit]);
        
    }
    void reverseString(vector<char>& s) {
        solve(s, 0, s.size() - 1);    
        }
};