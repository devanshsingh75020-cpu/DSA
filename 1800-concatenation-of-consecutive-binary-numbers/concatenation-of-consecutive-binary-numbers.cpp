class Solution {
public:
    int concatenatedBinary(int n) {
        string str = "";
        int mod = 1e9 + 7;
        for(int i = 1; i <= n; i++) {
            int num = i; 
            string st = "";
            while(num > 0) {
                int rem = num % 2;
                st.push_back(rem + '0'); 
                num /= 2;
            }
            reverse(st.begin(), st.end());
            str += st;
        }
        long long ans = 0;

        for(int i = 0; i < str.size(); i++) {
            ans = (ans * 2 + (str[i] - '0')) % mod;
        }

        return ans;
    }
};