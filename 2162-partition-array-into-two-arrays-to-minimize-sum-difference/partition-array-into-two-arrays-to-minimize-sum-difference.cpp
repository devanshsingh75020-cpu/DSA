class Solution {
public:
    vector<vector<int>> left, right;

    void solveLeft(vector<int>& nums, int idx, int end, int cnt, int sum) {
        if (idx == end) {
            left[cnt].push_back(sum);
            return;
        }

        solveLeft(nums, idx + 1, end, cnt + 1, sum + nums[idx]);
        solveLeft(nums, idx + 1, end, cnt, sum);
    }

    void solveRight(vector<int>& nums, int idx, int end, int cnt, int sum) {
        if (idx == end) {
            right[cnt].push_back(sum);
            return;
        }

        solveRight(nums, idx + 1, end, cnt + 1, sum + nums[idx]);
        solveRight(nums, idx + 1, end, cnt, sum);
    }

    int minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 2;

        left.resize(n + 1);
        right.resize(n + 1);

        solveLeft(nums, 0, n, 0, 0);
        solveRight(nums, n, m, 0, 0);

        for (int i = 0; i <= n; i++)
            sort(right[i].begin(), right[i].end());

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for (int i = 0; i <= n; i++) {

            for (int leftSum : left[i]) {

                int need = total / 2 - leftSum;

                auto &v = right[n - i];
                auto it = lower_bound(v.begin(), v.end(), need);

                if (it != v.end()) {
                    int chosen = leftSum + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }

                if (it != v.begin()) {
                    --it;
                    int chosen = leftSum + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }
            }
        }
        return ans;
    }
};