class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        unordered_map<string, int> need;
        for (auto &word : words)
            need[word]++;

        int wordLen = words[0].size();
        int totalWords = words.size();
        int n = s.size();

        // Try every possible starting offset
        for (int start = 0; start < wordLen; start++) {

            unordered_map<string, int> have;

            int left = start;
            int count = 0;

            for (int right = start; right + wordLen <= n; right += wordLen) {

                string word = s.substr(right, wordLen);

                // Invalid word
                if (need.find(word) == need.end()) {
                    have.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                have[word]++;
                count++;

                // Remove extra copies
                while (have[word] > need[word]) {
                    string leftWord = s.substr(left, wordLen);
                    have[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // Found a valid window
                if (count == totalWords) {
                    ans.push_back(left);

                    // Slide window by one word
                    string leftWord = s.substr(left, wordLen);
                    have[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};