class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0])
            return a[1] > b[1];

        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> lis;

        for(int i = 0; i < envelopes.size(); i++) {
            int h = envelopes[i][1];

            // Binary search
            int pos = lower_bound(lis.begin(), lis.end(), h) - lis.begin();

            if(pos == lis.size())
                lis.push_back(h);
            else
                lis[pos] = h;
        }
        return lis.size();
    }
};