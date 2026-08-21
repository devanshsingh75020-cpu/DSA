class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;

        for(int i = 0; i < word.size(); i++) {
            mp[word[i]]++;
        }

        int ans = INT_MAX;
        for(auto x : mp) {
            int base = x.second;
            int curr = 0;

            for(auto y : mp) {
                int freq = y.second;

                if(freq < base) {
                    curr += freq;
                }
                else if(freq > base + k) {
                    curr += freq - (base + k);
                }
            }
            ans = min(ans, curr);
        }
        return ans;
    }
};