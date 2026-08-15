class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        if (a.first != b.first)
            return a.first < b.first;

        return a.second > b.second;
    }

    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<pair<int,int>> q;

        for (auto &query : queries) {
            q.push_back({query[0], query[1]});
        }

        // Sort by starting point
        // If same start, farther reach first
        sort(q.begin(), q.end(), cmp);

        // Max heap based on ending point
        priority_queue<int> pq;

        // Difference array to track currently active queries
        vector<int> diff(n + 1, 0);

        int active = 0;
        int j = 0;
        int used = 0;

        for (int i = 0; i < n; i++) {

            active += diff[i];

            // Add all queries starting at or before i
            while (j < m && q[j].first <= i) {
                pq.push(q[j].second);
                j++;
            }

            // We need at least nums[i] active queries
            while (active < nums[i]) {

                // No query available
                if (pq.empty())
                    return -1;

                int r = pq.top();
                pq.pop();

                // This query cannot cover i
                if (r < i)
                    continue;

                // Use this query
                active++;
                used++;

                // Its effect ends after r
                if (r + 1 <= n)
                    diff[r + 1]--;
            }
        }

        // We used 'used' queries.
        // The remaining queries can be removed.
        return m - used;
    }
};