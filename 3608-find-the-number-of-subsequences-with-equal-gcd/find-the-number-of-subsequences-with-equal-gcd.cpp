class Solution {
public:
    static const int MOD = 1e9 + 7;
    int dp[205][201][201];

    int solve(vector<int>& nums, int idx, int gcd1, int gcd2) {
        if (idx == nums.size()) {
            return (gcd1 != 0 && gcd1 == gcd2);
        }

        if (dp[idx][gcd1][gcd2] != -1)
            return dp[idx][gcd1][gcd2];

        long long ans = 0;

        // Don't take current element
        ans += solve(nums, idx + 1, gcd1, gcd2);

        // Put in first subsequence
        int newGcd1 = (gcd1 == 0) ? nums[idx] : gcd(gcd1, nums[idx]);
        ans += solve(nums, idx + 1, newGcd1, gcd2);

        // Put in second subsequence
        int newGcd2 = (gcd2 == 0) ? nums[idx] : gcd(gcd2, nums[idx]);
        ans += solve(nums, idx + 1, gcd1, newGcd2);

        return dp[idx][gcd1][gcd2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 0);
    }
};