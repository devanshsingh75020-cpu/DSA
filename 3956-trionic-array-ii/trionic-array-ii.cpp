class Solution {
public:
    int n;
    vector<vector<long long>> dp;

    long long solve(int i, int trend, vector<int>& nums) {
        if (i == n) {
            if (trend == 3) return 0;
            return LLONG_MIN/2;
        }

        if (dp[i][trend] != LLONG_MIN)
            return dp[i][trend];

        long long take = LLONG_MIN/2;
        long long skip = LLONG_MIN/2;

        if (trend == 0)
            skip = solve(i + 1, 0, nums);

        if (trend == 3)
            take = nums[i];

        if (i + 1 < n) {
            int curr = nums[i];
            int next = nums[i + 1];

            if (trend == 0) {
                if (next > curr)
                    take = max(take, 1LL * curr + solve(i + 1, 1, nums));
            }
            else if (trend == 1) {
                if (next > curr)
                    take = max(take, 1LL * curr + solve(i + 1, 1, nums));
                else if (next < curr)
                    take = max(take, 1LL * curr + solve(i + 1, 2, nums));
            }
            else if (trend == 2) {
                if (next < curr)
                    take = max(take, 1LL * curr + solve(i + 1, 2, nums));
                else if (next > curr)
                    take = max(take, 1LL * curr + solve(i + 1, 3, nums));
            }
            else if (trend == 3) {
                if (next > curr)
                    take = max(take, 1LL * curr + solve(i + 1, 3, nums));
            }
        }
        return dp[i][trend] = max(take, skip);
    }

    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        dp.assign(n + 1, vector<long long>(4, LLONG_MIN));

        return solve(0, 0, nums);
    }
};