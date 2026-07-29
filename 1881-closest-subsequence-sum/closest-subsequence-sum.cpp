class Solution {
public:
    vector<int> subsetsumA;
    vector<int> subsetsumB;
    int n;

    void solve1(vector<int>& nums, int idx, int sum) {
        if (idx == n / 2) {
            subsetsumA.push_back(sum);
            return;
        }

        solve1(nums, idx + 1, sum + nums[idx]);
        solve1(nums, idx + 1, sum);
    }

    void solve2(vector<int>& nums, int idx, int sum) {
        if (idx == n) {
            subsetsumB.push_back(sum);
            return;
        }

        solve2(nums, idx + 1, sum + nums[idx]);
        solve2(nums, idx + 1, sum);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        n = nums.size();

        solve1(nums, 0, 0);
        solve2(nums, n / 2, 0);

        sort(subsetsumB.begin(), subsetsumB.end());

        int ans = INT_MAX;

        for (int x : subsetsumA) {
            int req = goal - x;

            auto it = lower_bound(subsetsumB.begin(), subsetsumB.end(), req);

            if (it != subsetsumB.end())
                ans = min(ans, abs(goal - (x + *it)));

            if (it != subsetsumB.begin()) {
                --it;
                ans = min(ans, abs(goal - (x + *it)));
            }
        }
        return ans;
    }
};