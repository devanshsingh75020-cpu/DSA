class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();

        priority_queue<int> pq;
        vector<pair<double,int>> info;

        for (int i = 0; i < n; i++) {
            info.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        sort(info.begin(), info.end());

        int qsum = 0;

        for (int i = 0; i < k; i++) {
            qsum += info[i].second;
            pq.push(info[i].second);
        }
        double ans = info[k - 1].first * qsum;

        for (int i = k; i < n; i++) {
            qsum += info[i].second;
            pq.push(info[i].second);

            qsum -= pq.top();
            pq.pop();

            ans = min(ans, info[i].first * qsum);
        }
        return ans;
    }
};