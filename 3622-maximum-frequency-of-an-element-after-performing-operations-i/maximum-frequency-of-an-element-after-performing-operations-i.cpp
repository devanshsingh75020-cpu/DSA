class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxel = *max_element(nums.begin(), nums.end());

        unordered_map<int, int> elfreq;

        for (int x : nums)
            elfreq[x]++;

        int OFFSET = k;

        vector<int> diffarr(maxel + 2 * k + 2, 0);

        for (int x : nums) {
            diffarr[x - k + OFFSET]++;
            diffarr[x + k + 1 + OFFSET]--;
        }

        for (int i = 1; i < diffarr.size(); i++)
            diffarr[i] += diffarr[i - 1];

        int ans = 0;

        for (int i = 0; i < diffarr.size(); i++) {
            int value = i - OFFSET;

            int currfreq = elfreq[value];
            int needconversion = max(0, diffarr[i] - currfreq);

            int totalfreq = currfreq + min(needconversion, numOperations);

            ans = max(ans, totalfreq);
        }

        return ans;
    }
};