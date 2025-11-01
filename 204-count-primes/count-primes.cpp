class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> ans;
        for(long long i = 2; i < n; i++){
            if(isPrime[i]){
                ans.push_back(i);
                for(long long j = 2 * i; j < n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        return ans.size();
    }
};