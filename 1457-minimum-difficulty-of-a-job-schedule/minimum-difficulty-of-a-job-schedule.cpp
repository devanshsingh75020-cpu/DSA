class Solution {
public:

    int solve(vector<int>& jobDifficulty, int d, int idx, vector<vector<int>> &dp) {
        int n = jobDifficulty.size();
        if(d == 1) {
            int maxi = INT_MIN;
            for(int i = idx; i < n; i++) {
                maxi = max(maxi, jobDifficulty[i]);
            }
            return maxi;
        }
        if(dp[d][idx]!=-1) return dp[d][idx];

        int maxD = 0;
        int finalresult = INT_MAX;

        for(int i = idx; i <= n - d; i++) {
            maxD = max(maxD, jobDifficulty[i]);
            int next = solve(jobDifficulty, d - 1, i + 1,dp);
            finalresult = min(finalresult, maxD + next);
        }
        return  dp[d][idx]=finalresult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(d+1,vector<int>(n+1,-1));
        if(d > n)  return -1;
        return solve(jobDifficulty, d, 0,dp);
    }
};