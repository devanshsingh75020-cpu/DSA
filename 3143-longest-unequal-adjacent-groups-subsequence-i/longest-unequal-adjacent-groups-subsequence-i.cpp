class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans1, ans2;

        // Start from index 0
        int last = groups[0];
        ans1.push_back(words[0]);

        for (int i = 1; i < words.size(); i++) {
            if (groups[i] != last) {
                ans1.push_back(words[i]);
                last = groups[i];
            }
        }

        // Start from index 1
        if (words.size() > 1) {
            last = groups[1];
            ans2.push_back(words[1]);

            for (int i = 2; i < words.size(); i++) {
                if (groups[i] != last) {
                    ans2.push_back(words[i]);
                    last = groups[i];
                }
            }
        }
        return (ans1.size() >= ans2.size()) ? ans1 : ans2;
    }
};