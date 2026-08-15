class Solution {
public:
    vector<long long> dp;
    long long solve(vector<vector<int>>& rides, int idx) {
        if(idx >= rides.size())  return 0;

        if(dp[idx] != -1)  return dp[idx];

        int start = rides[idx][0];
        int end = rides[idx][1];
        int tip = rides[idx][2];
        long long earn = end - start + tip;

        int low = idx + 1;
        int high = rides.size();
        while(low < high) {
            int mid = (low + high) / 2;
            if(rides[mid][0] >= end)
                high = mid;
            else
                low = mid + 1;
        }
        long long take =earn + solve(rides, low);
        long long skip =solve(rides, idx + 1);
        return dp[idx] = max(take, skip);
    }
    long long maxTaxiEarnings(int n,vector<vector<int>>& rides) {

        sort(rides.begin(), rides.end());
        dp.resize(rides.size(), -1);
        return solve(rides, 0);
    }
};