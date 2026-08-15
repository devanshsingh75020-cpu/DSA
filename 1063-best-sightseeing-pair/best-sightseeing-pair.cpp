class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> A(n), B(n);

        for (int i = 0; i < n; i++) {
            A[i] = values[i] + i;
            B[i] = values[i] - i;
        }

        int maxi = A[0];
        int ans = INT_MIN;
        for (int j = 1; j < n; j++) {
            ans = max(ans, maxi + B[j]);
            maxi = max(maxi, A[j]);
        }

        return ans;
    }
};