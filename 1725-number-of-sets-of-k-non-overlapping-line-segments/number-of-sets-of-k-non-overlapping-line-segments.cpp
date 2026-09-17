class Solution {
public:
    int n, k;
    int mod = 1e9 + 7;
    int dp[1005][1005][2]; // end state can be inferred, so 3D is sufficient: dp[idx][cnt][is_open]

    long long f(int idx, int cnt, bool is_open) {
        if (cnt == k && !is_open)
            return 1; // Successfully formed k non-overlapping segments

        if (idx == n)
            return 0; // Reached end of points without completing k segments

        int &ans = dp[idx][cnt][is_open];
        if (ans != -1)
            return ans;

        long long res = 0;

        if (!is_open) {
            // Case 1: Don't start a segment at idx
            res = (res + f(idx + 1, cnt, false)) % mod;

            // Case 2: Start a segment at idx (remains open)
            res = (res + f(idx + 1, cnt, true)) % mod;
        } else {
            // Case 1: Continue the open segment past idx
            res = (res + f(idx + 1, cnt, true)) % mod;

            // Case 2: Close the segment at idx (cnt increases to cnt + 1)
            // Since point idx can ALSO start a new segment, we re-evaluate at idx with is_open = false
            res = (res + f(idx, cnt + 1, false)) % mod;
        }

        return ans = res;
    }

    int numberOfSets(int n, int k) {
        this->n = n;
        this->k = k;
        memset(dp, -1, sizeof(dp));
        return f(0, 0, false);
    }
};