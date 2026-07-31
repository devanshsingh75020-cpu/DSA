class Solution {
public:
    int dp[1001][1001];
    int mod=1e9+7;
    int solve(int n, int k){
        if(n == 0) return 0;

        if(k == 0) return 1;

        if(dp[n][k]!=-1) return dp[n][k];

        int ans=0;
        for(int inv=0; inv<=min(k,n-1); inv++){
            ans= (ans+solve(n-1,k-inv)) % mod;
        }

        return dp[n][k]=ans;
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};