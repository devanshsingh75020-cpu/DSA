class Solution {
public:
    long long dp[21][21][3];

    long long solve(vector<int>& nums, int i, int j, int chance){
        if(i > j) return 0;

        if(dp[i][j][chance] != -1)
            return dp[i][j][chance];

        if(chance == 1){
            long long front = nums[i] + solve(nums, i+1, j, 2);
            long long back = nums[j] + solve(nums, i, j-1, 2);

            return dp[i][j][chance] = max(front, back);
        }
        else{
            long long front = solve(nums, i+1, j, 1) - nums[i];
            long long back = solve(nums, i, j-1, 1) - nums[j];

            return dp[i][j][chance] = min(front, back);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, nums.size()-1, 1) >= 0;
    }
};