class Solution {
public:
    map<tuple<int,int,int>,int>dp;
    
    int solve(int i, int jump, int lastop, int k){
        if(i>k+1) return 0;

        auto state=make_tuple(i,jump,lastop);

        if(dp.count(state)) return dp[state];

        int ans=(i==k);
        
        if(i>0 && lastop == 0)
           ans+=solve(i-1,jump,1,k);
        
        ans+=solve(i+(1<<jump), jump+1, 0,k);

        return dp[state]=ans;

    }
    int waysToReachStair(int k) {
        return solve(1, 0, 0, k);
    }
};