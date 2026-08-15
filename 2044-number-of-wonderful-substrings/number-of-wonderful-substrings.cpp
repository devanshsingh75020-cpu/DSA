class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<int, ll> mp;
        mp[0] = 1; 
        int cum_xor = 0;
        ll result = 0;
        for (char ch : word) {
            int shift = ch - 'a';
            cum_xor ^= (1 << shift);
            result += mp[cum_xor];
            for (int i = 0; i < 10; i++) {
                int check_xor = cum_xor ^ (1 << i);
                result += mp[check_xor];
            }
            mp[cum_xor]++;
        }return result;
    }
};