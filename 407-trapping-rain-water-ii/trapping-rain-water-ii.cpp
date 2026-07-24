class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<PP>> boundaryCells;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int r = 0; r < m; ++r) {
            for (int c : {0, n - 1}) {
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        for (int c = 0; c < n; ++c) {
            for (int r : {0, m - 1}) { 
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        int water=0;
        while(!boundaryCells.empty()){
            auto [height, cell] = boundaryCells.top();
            boundaryCells.pop();

            int i = cell.first;
            int j = cell.second;

            for (vector<int>& dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];


                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                    
                    water += max(0, height - heightMap[ni][nj]);
                    
                    boundaryCells.push({max(height, heightMap[ni][nj]), {ni, nj}});

                    visited[ni][nj] = true;
                }
            }
        }
        return water;
    }
};