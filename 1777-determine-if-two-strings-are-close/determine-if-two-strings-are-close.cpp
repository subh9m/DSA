class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        set<char>st1;
        set<char>st2;

        for(char c: word1)st1.insert(c);
        for(char c: word2)st2.insert(c);

        if(st1 != st2) return false;
        if(n1 != n2) return false;

        unordered_map<char, int>mpp1;
        unordered_map<char, int>mpp2;

        for(auto ch: word1){
            mpp1[ch]++;
        }

        for(auto ch: word2){
            mpp2[ch]++;
        }

        vector<int>freq1;
        vector<int>freq2;

        for(auto it: mpp1){
            freq1.push_back(it.second);
        }
        for(auto it: mpp2){
            freq2.push_back(it.second);
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        if(freq1 != freq2) return false;

        return true;

    }
};