class Solution {
public:
    const long long INF = 1e18;
    long long dp[105][10005];
    long long solve(vector<int>&robot, vector<int> & fact, int i, int j){
        if(i == robot.size()) return 0;

        if(j == fact.size()) return INF;

        if(dp[i][j]!=-1) return dp[i][j];

        long long take=abs(robot[i]-fact[j]) + solve(robot, fact, i+1, j+1);

        long long skip=solve(robot, fact, i, j+1);

        return dp[i][j]=min(take,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        memset(dp,-1,sizeof(dp));
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<int>fact;

        for(int i=0; i<factory.size(); i++){
            int cap=factory[i][1];
            int pos=factory[i][0];

            while(cap>0){
                fact.push_back(pos);
                cap--;
            }
        }
        return solve(robot, fact, 0, 0);
    }
};