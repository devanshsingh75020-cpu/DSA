class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> prefix(n);
        set<char> left;
        for (int i = 0; i < n; i++) {
            left.insert(s[i]);
            prefix[i] = left.size();
        }

        set<char> right;
        for (int i = n - 1; i > 0; i--) {
            right.insert(s[i]);

            if (prefix[i - 1] == right.size()) {
                ans++;
            }
        }
        return ans;
    }
};