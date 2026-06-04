class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;

        int n = s.size();
        int m = p.size();

        if(m > n){
            return result;
        }

        vector<int>pCount(26, 0);
        vector<int>freqCount(26, 0);

        
        for(int i = 0; i < m; i++){
            pCount[p[i] - 'a']++;
            freqCount[s[i] - 'a']++;
        }

        if(pCount == freqCount){
            result.push_back(0);
        }

        for(int i = m; i < n; i++){
            freqCount[s[i] - 'a']++;
            freqCount[s[i-m] - 'a']--;

            if(pCount == freqCount){
                result.push_back(i-m+1);
            }
        }

        return result;
    }
};