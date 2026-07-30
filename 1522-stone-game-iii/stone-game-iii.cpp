class Solution {
public:
    int dp[50001][2];

    int solve(vector<int>& stoneValue, int i, int chance){
        if(i >= stoneValue.size()) return 0;

        if(dp[i][chance] != INT_MIN)
            return dp[i][chance];

        int sum = 0;

        if(chance == 1){ // Alice
            int ans = INT_MIN;

            for(int k = 0; k < 3 && i + k < stoneValue.size(); k++){
                sum += stoneValue[i + k];
                ans = max(ans, sum + solve(stoneValue, i + k + 1, 0));
            }

            return dp[i][chance] = ans;
        }
        else{ // Bob
            int ans = INT_MAX;

            for(int k = 0; k < 3 && i + k < stoneValue.size(); k++){
                sum += stoneValue[i + k];
                ans = min(ans, solve(stoneValue, i + k + 1, 1) - sum);
            }

            return dp[i][chance] = ans;
        }
    }

    string stoneGameIII(vector<int>& stoneValue) {
        for(int i = 0; i <= 50000; i++)
            dp[i][0] = dp[i][1] = INT_MIN;

        int diff = solve(stoneValue, 0, 1);

        if(diff > 0) return "Alice";
        if(diff < 0) return "Bob";
        return "Tie";
    }
};
