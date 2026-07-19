class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();

        vector<int> diff(n + 1, 0);

        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] += val;
            if (r + 1 < n)
                diff[r + 1] -= val;
        }

        vector<int> cumsum(n, 0);
        cumsum[0] = diff[0];

        for (int i = 1; i < n; i++) {
            cumsum[i] = cumsum[i - 1] + diff[i];
        }

        for (int i = 0; i < n; i++) {
            if (cumsum[i] < nums[i])
                return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();

        if (!check(nums, queries, m))
            return -1;

        int low = 0;
        int high = m;
        int ans = m;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums, queries, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};