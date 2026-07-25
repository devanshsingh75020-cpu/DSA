class Solution {
public:
    vector<vector<int>>dp;
    int m,n;

    int solve(int prev, int curr, vector<string>& strs){
        if(curr == n) return 0;

        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];

        int notTake = solve(prev, curr + 1, strs);

        int take=0;
        bool ok=true;

        if (prev == -1) {
            take = 1 + solve(curr, curr + 1, strs);
        } 
        else {
            for (int i = 0; i < m; i++) {
                if (strs[i][prev] > strs[i][curr]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                take = 1 + solve(curr, curr + 1, strs);
        }
        return dp[prev+1][curr]=max(take,notTake);
    }
    int minDeletionSize(vector<string>& strs) {
        m=strs.size();
        n=strs[0].size();

        dp.assign(n+2,vector<int> (n+2,-1));

        return n-solve(-1, 0, strs);
    }
};