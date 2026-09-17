class Solution {
public:
    int n, k;
    int mod = 1e9 + 7;
    int dp[1001][1001][2];
    long long f(int idx, int cnt, bool isopen) {
        if (cnt == k && !isopen)  return 1;

        if (idx == n)  return 0;

        if (dp[idx][cnt][isopen] != -1)
            return dp[idx][cnt][isopen];

        long long res = 0;

        if (!isopen) {
            res = (res + f(idx + 1, cnt, false)) % mod;

            res = (res + f(idx + 1, cnt, true)) % mod;
        } else {
            res = (res + f(idx + 1, cnt, true)) % mod;

            res = (res + f(idx, cnt + 1, false)) % mod;
        }
        return dp[idx][cnt][isopen] = res;
    }

    int numberOfSets(int n, int k) {
        this->n = n;
        this->k = k;
        memset(dp, -1, sizeof(dp));
        return f(0, 0, false);
    }
};