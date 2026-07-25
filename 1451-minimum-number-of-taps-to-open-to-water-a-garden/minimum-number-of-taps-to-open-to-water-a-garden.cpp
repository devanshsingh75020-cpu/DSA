class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> range;

        for(int i = 0; i < ranges.size(); i++) {
            int low = max(0, i - ranges[i]);
            int high = min(n, i + ranges[i]);

            range.push_back({low, high});
        }
        sort(range.begin(), range.end(), cmp);

        int count = 0;
        int end = 0;//max garden covered till now
        int farthest = 0;//max right till current tap
        int i = 0;

        while(end < n) {
            while(i<range.size() && range[i][0]<=end){
                farthest=max(farthest,range[i][1]);
                i++;
            }
            if(farthest==end){
                return -1;
            }
            count++;
            end=farthest;
        }
        return count;
    }
};