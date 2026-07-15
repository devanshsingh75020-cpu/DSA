class Solution {
public:

    vector<vector<int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int m, n;
    int dp[501][501][4][2];

    int solve(int i, int j, int d, bool canTurn, int val, vector<vector<int>>& grid) {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];

        if(ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] != val) {
            return 0;
        }

        if(dp[ni][nj][d][canTurn] != -1) {
            return dp[ni][nj][d][canTurn];
        }

        int result = 0;
        int keepMoving = 1 + solve(ni, nj, d, canTurn, val == 2 ? 0 : 2, grid);
        result = max(result, keepMoving);

        if(canTurn == true) {
            int turnAndMove = max(keepMoving, 1 + solve(ni, nj, (d+1)%4, false, val == 2 ? 0 : 2, grid));
            result = max(result, turnAndMove);
        }

        return dp[ni][nj][d][canTurn] = result;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));

        int result = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    for(int d = 0; d <= 3; d++) {
                        result = max(result, 1 + solve(i, j, d, true, 2, grid));
                    }
                }
            }
        }
        return result;

    }
};