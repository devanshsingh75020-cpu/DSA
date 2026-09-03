class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int a = 0, b = 0, c = 0;

        for(char ch : s) {
            if(ch == 'a') a++;
            else if(ch == 'b') b++;
            else c++;
        }

        if(a < k || b < k || c < k)
            return -1;

        int maxA = a - k;
        int maxB = b - k;
        int maxC = c - k;

        int l = 0;
        int ca = 0, cb = 0, cc = 0;
        int maxlen = 0;

        for(int r = 0; r < n; r++) {

            if(s[r] == 'a') ca++;
            else if(s[r] == 'b') cb++;
            else cc++;

            while(ca > maxA || cb > maxB || cc > maxC) {
                if(s[l] == 'a') ca--;
                else if(s[l] == 'b') cb--;
                else cc--;

                l++;
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return n - maxlen;
    }
};