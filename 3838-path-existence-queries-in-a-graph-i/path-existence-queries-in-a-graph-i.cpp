class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unionSet(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return false;

        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];
        return true;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first <= maxDiff) {
                unionSet(arr[i].second, arr[i - 1].second);
            }
        }
        vector<bool> ans;

        for (auto &q : queries) {
            ans.push_back(find(q[0]) == find(q[1]));
        }
        return ans;
    }
};