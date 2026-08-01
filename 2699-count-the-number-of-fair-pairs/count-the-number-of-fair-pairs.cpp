class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long count = 0;
        for(int i = 0; i < nums.size(); i++) {
            int low = lower - nums[i];
            int up = upper - nums[i];

            auto left = lower_bound(nums.begin() + i + 1, nums.end(), low);
            auto right = upper_bound(nums.begin() + i + 1, nums.end(), up);

            count += (right - left);
        }
        return count;
    }
};