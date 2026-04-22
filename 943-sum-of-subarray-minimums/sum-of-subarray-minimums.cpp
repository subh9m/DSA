class Solution {
public:
    vector<int> findNextSmaller(vector<int>&arr){
        int n = arr.size();
        vector<int> nse(n);

        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n: st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> findPreviousSmallerOrEqual(vector<int>&arr){
        int n = arr.size();
        vector<int>psee(n);

        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();

    
        int sum = 0;
        vector<int>nse = findNextSmaller(arr);
        vector<int>psee = findPreviousSmallerOrEqual(arr);

        for(int i = 0; i < n; i++){
           int left = i - psee[i];
           int right = nse[i] - i;

           long long freq = (left * right * 1LL);
           int val = (freq * arr[i] * 1LL) % mod;
           sum = (val + sum) % mod;
        }

        return sum;
    }
};