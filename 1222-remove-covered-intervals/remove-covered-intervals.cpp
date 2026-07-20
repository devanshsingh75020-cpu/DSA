class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        auto comp = [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0])
                return a[1] > b[1];   // same start, larger end first
            
            return a[0] < b[0];        // smaller start first
        };

        sort(intervals.begin(), intervals.end(), comp);

        int ans = intervals.size();

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            int currstart = intervals[i][0];
            int currend = intervals[i][1];

            if(currstart >= start && currend <= end) {
                ans--;
            }
            else {
                start = currstart;
                end = currend;
            }
        }
        return ans;
    }
};