class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = __builtin_popcount(num1);
        int cnt2 = __builtin_popcount(num2);

        int ans = num1;

        if (cnt1 > cnt2) {
            int extra = cnt1 - cnt2;

            // Remove lowest set bits
            for (int i = 0; i < 32 && extra > 0; i++) {
                if ((ans >> i) & 1) {
                    ans ^= (1 << i);
                    extra--;
                }
            }
        }
        else if (cnt1 < cnt2) {
            int extra = cnt2 - cnt1;

            // Add lowest unset bits
            for (int i = 0; i < 32 && extra > 0; i++) {
                if (((ans >> i) & 1) == 0) {
                    ans |= (1 << i);
                    extra--;
                }
            }
        }

        return ans;
    }
};