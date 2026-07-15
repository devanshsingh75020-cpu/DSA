class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();

        int sr, sc;
        int totalKeys = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    sr = i;
                    sc = j;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    totalKeys++;
            }
        }

        queue<pair<pair<int,int>, string>> q;
        set<tuple<int,int,string>> vis;

        q.push({{sr, sc}, ""});
        vis.insert({sr, sc, ""});

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto cur = q.front();
                q.pop();

                int x = cur.first.first;
                int y = cur.first.second;
                string keys = cur.second;

                if ((int)keys.size() == totalKeys)
                    return steps;

                for (auto &d : dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;

                    char ch = grid[nx][ny];

                    if (ch == '#')
                        continue;

                    string newKeys = keys;

                    // Pick up key
                    if (ch >= 'a' && ch <= 'f') {
                        if (newKeys.find(ch) == string::npos) {
                            newKeys += ch;
                            sort(newKeys.begin(), newKeys.end());
                        }
                    }

                    // Check lock
                    if (ch >= 'A' && ch <= 'F') {
                        if (newKeys.find(ch - 'A' + 'a') == string::npos)
                            continue;
                    }

                    if (!vis.count({nx, ny, newKeys})) {
                        vis.insert({nx, ny, newKeys});
                        q.push({{nx, ny}, newKeys});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};