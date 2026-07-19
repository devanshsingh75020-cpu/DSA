class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        vector<int> snum(n);
        for (int i = 0; i < n; i++) {
            snum[i] = s[i] - 'a';
        }

        vector<int> diff(n + 1, 0);

        for (int i = 0; i < shifts.size(); i++) {
            int l = shifts[i][0];
            int r = shifts[i][1];
            int dir = shifts[i][2];

            int x = (dir == 1) ? 1 : -1;

            diff[l] += x;
            diff[r + 1] -= x;
        }

        vector<int> cumsum(n, 0);
        cumsum[0] = diff[0];

        for (int i = 1; i < n; i++) {
            cumsum[i] = cumsum[i - 1] + diff[i];
        }

        for (int i = 0; i < n; i++) {
            snum[i] = (snum[i] + cumsum[i]) % 26;
            if (snum[i] < 0)
                snum[i] += 26;
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            ans.push_back(char('a' + snum[i]));
        }

        return ans;
    }
};