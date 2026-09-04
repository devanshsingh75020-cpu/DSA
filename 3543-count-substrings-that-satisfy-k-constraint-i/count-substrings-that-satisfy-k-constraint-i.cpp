class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        int n = s.size();

        for(int len = 1; len <= n; len++) {
            for(int i = 0; i + len <= n; i++) {
                int zeros = 0;
                int ones = 0;
                for(int j = i; j < i + len; j++) {
                    if(s[j] == '0')
                        zeros++;
                    else
                        ones++;
                }
                if(zeros <= k || ones <= k)
                    ans++;
            }
        }
        return ans;
    }
};