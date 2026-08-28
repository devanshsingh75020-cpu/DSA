class Solution {
public:
    int m, n;
    int dr[2][2] = {{0, 1}, {1, 0}};
    void dfs(int i, int j, vector<vector<int>>& land, vector<vector<int>>& vis, vector<int>& row) {

        vis[i][j] = 1;

        row[2] = max(row[2], i);
        row[3] = max(row[3], j);

        for(int k = 0; k < 2; k++) {
            int ni = i + dr[k][0];
            int nj = j + dr[k][1];

            if(ni >= 0 && ni < m && nj >= 0 && nj < n && land[ni][nj] == 1 && vis[ni][nj] == 0) {

                dfs(ni, nj, land, vis, row);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(land[i][j] == 1 && vis[i][j] == 0) {
                    vector<int> row = {i, j, i, j};
                    dfs(i, j, land, vis, row);
                    ans.push_back(row);
                }
            }
        }
        return ans;
    }
};