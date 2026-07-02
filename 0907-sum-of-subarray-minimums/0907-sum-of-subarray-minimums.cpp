class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long MOD = 1e9 + 7;
        int n = arr.size();

        // Previous Smaller Element
        stack<int> st1;
        vector<int> pse(n, -1);

        for(int i = 0; i < n; i++) {
            while(!st1.empty() && arr[st1.top()] > arr[i]) {
                st1.pop();
            }

            if(!st1.empty()) {
                pse[i] = st1.top();
            }

            st1.push(i);
        }

        // Next Smaller Element
        stack<int> st2;
        vector<int> nse(n, n);

        for(int i = n - 1; i >= 0; i--) {
            while(!st2.empty() && arr[st2.top()] >= arr[i]) {
                st2.pop();
            }

            if(!st2.empty()) {
                nse[i] = st2.top();
            }

            st2.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            ans = (ans + (left * right % MOD) * arr[i] % MOD) % MOD;
        }

        return (int)ans;
    }
};