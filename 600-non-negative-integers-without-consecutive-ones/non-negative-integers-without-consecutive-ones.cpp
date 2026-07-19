class Solution {
public:
    string binary_s;
    int dp[32][2][2];
    int solve(int idx, int last, bool tight) {
        if (idx == binary_s.length()) return 1;

        if (dp[idx][last][tight] != -1) return dp[idx][last][tight];

        int ans = 0;
        int limit = tight ? (binary_s[idx] - '0') : 1;

        for (int bit = 0; bit <= limit; bit++) {
            if (last == 1 && bit == 1) continue;

            bool next_tight = tight && (bit == limit);
            
            ans += solve(idx + 1, bit, next_tight);
        }

        return dp[idx][last][tight] = ans;
    }
    int findIntegers(int n) {
        binary_s="";

        while (n > 0) {
            binary_s += (n % 2 == 0 ? '0' : '1');
            n /= 2;
        }
        reverse(binary_s.begin(), binary_s.end());

        memset(dp, -1, sizeof(dp));

        return solve(0,0,true);

    }
};