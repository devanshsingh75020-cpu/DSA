class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int m = words.size();
        int k = words[0].size();
        int window = m * k;

        unordered_map<string,int> need;

        for(auto &w : words)
            need[w]++;

        for(int i = 0; i + window <= s.size(); i++) {

            unordered_map<string,int> have;

            for(int j = 0; j < window; j += k) {

                string word = s.substr(i + j, k);
                have[word]++;
            }

            if(have == need)
                ans.push_back(i);
        }

        return ans;
    }
};