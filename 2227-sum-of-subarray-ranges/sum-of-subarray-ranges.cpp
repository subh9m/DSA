class Solution {
public:
    vector<int>NextGreaterElement(vector<int>&arr){
        int n = arr.size();
        vector<int>nge(n);

        stack<int>st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            nge[i] = st.empty()? n : st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int>NextSmallerElement(vector<int>&arr){
        int n = arr.size();
        vector<int>nse(n);

        stack<int>st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty()? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>PreviousGreaterOrEqualElement(vector<int>&arr){
        int n = arr.size();
        vector<int>pgee(n);

        stack<int>st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            pgee[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }
    vector<int>PreviousSmallerOrEqualElement(vector<int>&arr){
        int n = arr.size();
        vector<int>psee(n);

        stack<int>st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            psee[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    long long subSumMax(vector<int>&arr){
        int n = arr.size();

        long long sum = 0;
        vector<int>nge = NextGreaterElement(arr);
        vector<int>pgee = PreviousGreaterOrEqualElement(arr);

        for(int i = 0; i < n; i++){
            int left = i - pgee[i];
            int right = nge[i] - i;

            long long freq = (left* right * 1LL);
            long long num = (arr[i] * freq * 1LL);

            sum += num;
        }

        return sum;
    }

    long long subSumMin(vector<int>&arr){
        int n = arr.size();

        long long sum = 0;
        vector<int>nse = NextSmallerElement(arr);
        vector<int>psee = PreviousSmallerOrEqualElement(arr);

        for(int i = 0; i < n; i++){
            int left = i - psee[i];
            int right = nse[i] - i;

            long long freq = (left * right * 1LL);
            long long num = (arr[i] * freq * 1LL);

            sum += num;
        }

        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return (subSumMax(nums) - subSumMin(nums));
    }
};