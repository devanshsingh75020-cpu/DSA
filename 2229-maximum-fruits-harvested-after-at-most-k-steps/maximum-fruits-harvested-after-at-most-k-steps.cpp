class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<long long> pref(n + 1, 0);
        vector<int> pos(n);

        for(int i = 0; i < n; i++) {
            pos[i] = fruits[i][0];
            pref[i + 1] = pref[i] + fruits[i][1];
        }
        long long ans = 0;

        for(int x = 0; x <= k; x++) {
            int leftReach = startPos - x;
            int rightReach = startPos + max(0, k - 2 * x);

            int l = lower_bound(pos.begin(), pos.end(), leftReach) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), rightReach) - pos.begin() - 1;

            if(l <= r) {
                ans = max(ans, pref[r + 1] - pref[l]);
            }
        }
        for(int x = 0; x <= k; x++) {
            int rightReach = startPos + x;
            int leftReach = startPos - max(0, k - 2 * x);

            int l = lower_bound(pos.begin(), pos.end(), leftReach) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), rightReach) - pos.begin() - 1;

            if(l <= r) {
                ans = max(ans, pref[r + 1] - pref[l]);
            }
        }
        return ans;
    }
};