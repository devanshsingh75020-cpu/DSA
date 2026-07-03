class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        vector<int> freq(10, 0);

        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int x = grid[i][j];
                if (x < 1 || x > 9 || freq[x])
                    return false;
                freq[x] = 1;
            }
        }

        int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        for (int i = r; i < r + 3; i++) {
            if (grid[i][c] + grid[i][c + 1] + grid[i][c + 2] != sum)
                return false;
        }

        for (int j = c; j < c + 3; j++) {
            if (grid[r][j] + grid[r + 1][j] + grid[r + 2][j] != sum)
                return false;
        }

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum)
            return false;

        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (isMagic(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};