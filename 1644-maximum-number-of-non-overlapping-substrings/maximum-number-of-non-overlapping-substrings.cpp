class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n);
        vector<int> last(26, -1);

        for(int i = 0; i < n; i++) {
            first[s[i] - 'a'] =min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }
        vector<pair<int,int>> intervals;
        for(int i = 0; i < n; i++) {
            if(i != first[s[i] - 'a'])
                continue;

            int start = i;
            int end = last[s[i] - 'a'];
            bool valid = true;
            for(int j = start; j <= end; j++) {
                int ch = s[j] - 'a';
                if(first[ch] < start) {
                    valid = false;
                    break;
                }
                end = max(end, last[ch]);
            }
            if(valid) {
                intervals.push_back({end, start});
            }
        }
        sort(intervals.begin(), intervals.end());
        vector<string> ans;
        int prevEnd = -1;

        for(auto it : intervals) {
            int end = it.first;
            int start = it.second;

            if(start > prevEnd) {
                ans.push_back(s.substr(start,end - start + 1));
                prevEnd = end;
            }
        }
        return ans;
    }
};