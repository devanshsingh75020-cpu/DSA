class Solution {
public:
    long long solve(int idx, vector<long long>& prefix, vector<long long>& dp) {
        // Base case: at the last index, the player MUST take all remaining stones
        if (idx == prefix.size() - 1) 
            return prefix[idx];
            
        if (dp[idx] != LLONG_MIN) 
            return dp[idx];

        // Choice 1: Stop here and take prefix[idx] -> score is prefix[idx] - solve(idx + 1)
        // Choice 2: Skip index idx and move to idx + 1 -> score is solve(idx + 1)
        return dp[idx] = max(prefix[idx] - solve(idx + 1, prefix, dp), 
                             solve(idx + 1, prefix, dp));
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> prefix(n);
        prefix[0] = stones[0];
        
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        vector<long long> dp(n, LLONG_MIN);
        return solve(1, prefix, dp);
    }
};