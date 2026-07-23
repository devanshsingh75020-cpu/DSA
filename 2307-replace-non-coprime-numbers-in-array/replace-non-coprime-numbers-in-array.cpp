class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;

        for (int num : nums) {
            long long curr = num;

            while (!st.empty() && gcd((long long)st.top(), curr) > 1) {
                long long top = st.top();
                st.pop();
                curr = (top*curr) / gcd(top, curr);
            }
            st.push(curr);
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};