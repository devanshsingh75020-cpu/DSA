class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(101, 0);

        for (auto &log : logs) {
            diff[log[0] - 1950]++;
            diff[log[1] - 1950]--;
        }

        int ans = 1950;
        int population = 0;
        int mx = 0;

        for (int i = 0; i <= 100; i++) {
            population += diff[i];

            if (population > mx) {
                mx = population;
                ans = i + 1950;
            }
        }
        return ans;
    }
};