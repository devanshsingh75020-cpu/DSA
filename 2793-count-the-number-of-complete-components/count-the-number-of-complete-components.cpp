class Solution {
public:
    vector<int>parent,sz;

    int find(int x){
        if(parent[x]==x) return x;

        return parent[x] = find(parent[x]);
    }

     void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
         parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &e : edges)
            unite(e[0], e[1]);

        // leader -> vertices
        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        unordered_map<int, int> edgeCount;
        
        // leader -> edge count
        for (auto &e : edges) {
            int leader = find(e[0]);
            edgeCount[leader]++;
        }

        int ans = 0;

        for (auto &it : groups) {
            int leader = it.first;
            int vertices = it.second.size();

            long long required = 1LL * vertices * (vertices - 1) / 2;

            if (edgeCount[leader] == required)
                ans++;
        }
        return ans;        
    }
};