class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st;
        st.insert(1);

        long long ans = 1;

        for (int i = 0; i < n; i++) {
            ans = *st.begin();
            st.erase(st.begin());

            st.insert(ans * 2);
            st.insert(ans * 3);
            st.insert(ans * 5);
        }

        return ans;
    }
};