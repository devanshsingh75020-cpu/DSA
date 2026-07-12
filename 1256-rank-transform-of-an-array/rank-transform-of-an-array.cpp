class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        vector<vector<int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end());

        vector<int> ans(n);

        int rank = 1;
        ans[v[0][1]] = rank;

        for (int i = 1; i < n; i++) {

            if (v[i][0] != v[i - 1][0])
                rank++;

            ans[v[i][1]] = rank;
        }
        return ans;
    }
};