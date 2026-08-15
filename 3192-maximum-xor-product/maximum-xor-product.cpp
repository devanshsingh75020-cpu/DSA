class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long Xora = 0, Xorb = 0;
        long long mod = 1e9+7;
        for(long long i = 49; i >= n; i--) {
            bool a_bit = (a >> i) & 1;
            bool b_bit = (b >> i) & 1;
            if(a_bit) Xora |= (1LL << i);
            if(b_bit) Xorb |= (1LL << i);
        }
        for(long long i = n-1; i >= 0; i--) {
            bool a_bit = (a >> i) & 1;
            bool b_bit = (b >> i) & 1;
            if(a_bit == b_bit) {
                Xora |= (1LL << i);
                Xorb |= (1LL << i);
            } else {
                if(Xora < Xorb) {
                    Xora |= (1LL << i);
                } else {
                    Xorb |= (1LL << i);
                }
            }
        }
        return ((Xora % mod) * (Xorb % mod)) % mod;
    }
};