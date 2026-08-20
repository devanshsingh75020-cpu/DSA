class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Left -> Right correction
        for(int i = 1; i < m; i++) {
            int id1 = restrictions[i-1][0];
            int h1 = restrictions[i-1][1];

            int id2 = restrictions[i][0];
            int h2 = restrictions[i][1];

            int d = id2 - id1;

            restrictions[i][1] = min(h2, h1 + d);
        }

        // Right -> Left correction
        for(int i = m-2; i >= 0; i--) {
            int id1 = restrictions[i][0];
            int h1 = restrictions[i][1];

            int id2 = restrictions[i+1][0];
            int h2 = restrictions[i+1][1];

            int d = id2 - id1;

            restrictions[i][1] = min(h1, h2 + d);
        }

        int maxi = 0;

        // Find maximum peak between restrictions
        for(int i = 1; i < m; i++) {
            int id1 = restrictions[i-1][0];
            int h1 = restrictions[i-1][1];

            int id2 = restrictions[i][0];
            int h2 = restrictions[i][1];

            int d = id2 - id1;

            maxi = max(maxi,
                       max(h1, h2) + (d - abs(h1 - h2)) / 2);
        }

        // Buildings after the last restriction
        int lastId = restrictions.back()[0];
        int lastHeight = restrictions.back()[1];

        maxi = max(maxi, lastHeight + (n - lastId));

        return maxi;
    }
};