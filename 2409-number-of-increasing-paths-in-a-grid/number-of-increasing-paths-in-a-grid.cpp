class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1,0},{0,-1},{0,1},{1, 0}};
    int dp[1001][1001];
    
    bool isSafe(int i, int j) {
        return (i < m && i >= 0 && j < n && j >= 0);
    }
    
    long long MOD = 1e9+7;
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int answer = 1;
        
        for(auto &dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            
            if(isSafe(ni, nj) && grid[ni][nj] < grid[i][j]) {
                answer = (answer + dfs(grid, ni, nj)) % MOD;
            }
        }
        return dp[i][j] = answer;
    }
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        memset(dp, -1, sizeof(dp));
        
        int result = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result = (result + dfs(grid, i, j)) % MOD;
            }
        }
        return result;
    }
};