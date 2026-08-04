class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int cnt = 0;
        int mini = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i] ^ k;
            sum += max(nums[i], x);
            if(x > nums[i]) {
                cnt++;
            }
            mini = min(mini, abs(nums[i] - x));
        }

        if(cnt % 2 == 0)   return sum;
        return sum - mini;
    }
};