class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffarr(n + 1, 0);

        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            diffarr[l] += 1;
            if (r + 1 < n)
                diffarr[r + 1] -= 1;
        }

        vector<int> cumsum(n, 0);
        cumsum[0] = diffarr[0];

        for (int i = 1; i < n; i++) {
            cumsum[i] = cumsum[i - 1] + diffarr[i];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > cumsum[i])
                return false;
        }

        return true;
    }
};