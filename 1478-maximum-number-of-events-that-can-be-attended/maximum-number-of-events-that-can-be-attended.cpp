class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        int ans=0;
        int i=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        int lastday = 0;
        for(int j = 0; j < n; j++) {
            lastday = max(lastday, events[j][1]);
        }

        for(int day=events[0][0]; day<=lastday; day++){
             // add events starting on this day
            while(i < n && events[i][0] == day) {
                pq.push({events[i][1], events[i][0]});
                i++;
            }
             // remove expired events
            while(!pq.empty() && pq.top().first < day) {
                pq.pop();
            }
             // attend event
            if(!pq.empty()) {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};