class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int idx, int i, int j, int last,vector<vector<vector<vector<int>>>> &dp) {

        if (idx == s3.size())
            return (i == s1.size() && j == s2.size());

        if (dp[idx][i][j][last] != -1)
            return dp[idx][i][j][last];

        bool ans = false;

        // Take from s1
        if (i < s1.size() && s1[i] == s3[idx]) {
            ans |= solve(s1, s2, s3, idx + 1, i + 1, j, 0, dp);
        }

        // Take from s2
        if (j < s2.size() && s2[j] == s3[idx]) {
            ans |= solve(s1, s2, s3, idx + 1, i, j + 1, 1, dp);
        }

        return dp[idx][i][j][last] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<vector<vector<int>>>> dp(s3.size() + 1,vector<vector<vector<int>>>(s1.size() + 1,vector<vector<int>>(s2.size() + 1,vector<int>(2, -1))));

        return solve(s1, s2, s3, 0, 0, 0, 0, dp);
    }
};