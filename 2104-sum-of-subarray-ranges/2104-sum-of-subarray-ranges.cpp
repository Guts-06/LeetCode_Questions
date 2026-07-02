class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        stack<int> st1;
        vector<int> pse(n, -1);

        for (int i = 0; i < n; i++) {

            while (!st1.empty() && arr[st1.top()] > arr[i]) {
                st1.pop();
            }

            if (!st1.empty()) {
                pse[i] = st1.top();
            }

            st1.push(i);
        }

        stack<int> st2;
        vector<int> nse(n, n);

        for (int i = n - 1; i >= 0; i--) {

            while (!st2.empty() && arr[st2.top()] >= arr[i]) {
                st2.pop();
            }

            if (!st2.empty()) {
                nse[i] = st2.top();
            }

            st2.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - pse[i];
            long long right = nse[i] - i;

            ans += left * right * arr[i];
        }

        return ans;
    }

    long long sumSubarrayMax(vector<int>& arr) {

        int n = arr.size();

        stack<int> st1;
        vector<int> pge(n, -1);

        for (int i = 0; i < n; i++) {

            while (!st1.empty() && arr[st1.top()] < arr[i]) {
                st1.pop();
            }

            if (!st1.empty()) {
                pge[i] = st1.top();
            }

            st1.push(i);
        }

        stack<int> st2;
        vector<int> nge(n, n);

        for (int i = n - 1; i >= 0; i--) {

            while (!st2.empty() && arr[st2.top()] <= arr[i]) {
                st2.pop();
            }

            if (!st2.empty()) {
                nge[i] = st2.top();
            }

            st2.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - pge[i];
            long long right = nge[i] - i;

            ans += left * right * arr[i];
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {

        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};