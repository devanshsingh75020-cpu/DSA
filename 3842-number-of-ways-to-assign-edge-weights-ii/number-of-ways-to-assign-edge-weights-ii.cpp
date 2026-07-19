class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<vector<int>> up;
    vector<vector<int>> adj;
    vector<int> depth;
    vector<int> pow2;
    int LOG;

    void dfs(int node, int parent) {
        up[node][0] = parent;

        for (int j = 1; j < LOG; j++) {
            if (up[node][j - 1] != -1)
                up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for (int child : adj[node]) {
            if (child == parent) continue;
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = LOG - 1; j >= 0; j--) {
            if ((diff >> j) & 1)
                u = up[u][j];
        }

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != -1 && up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        adj.assign(n + 1, {});
        up.assign(n + 1, vector<int>(LOG, -1));
        depth.assign(n + 1, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);

        pow2.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (2LL * pow2[i - 1]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            int LCA = lca(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[LCA];

            if (dist == 0)
                ans.push_back(0);
            else
                ans.push_back(pow2[dist - 1]);
        }

        return ans;
    }
};