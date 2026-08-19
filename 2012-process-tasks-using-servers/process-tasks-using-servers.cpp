class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = tasks.size();
        vector<int> ans(n);

        // {weight, server index}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> available;

        // {finish time, server index}
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> busy;

        for(int i = 0; i < servers.size(); i++) {
            available.push({servers[i], i});
        }

        long long time = 0;
        for(int i = 0; i < n; i++) {
            time = max(time, (long long)i);

            // Move all finished servers to available
            while(!busy.empty() && busy.top().first <= time) {
                int id = busy.top().second;
                busy.pop();

                available.push({servers[id], id});
            }

            // No server available
            if(available.empty()) {
                time = busy.top().first;

                while(!busy.empty() && busy.top().first <= time) {
                    int id = busy.top().second;
                    busy.pop();

                    available.push({servers[id], id});
                }
            }

            // Smallest weight, then smallest index
            auto [weight, id] = available.top();
            available.pop();

            ans[i] = id;

            // This server will finish at time + task duration
            busy.push({time + tasks[i], id});
        }
        return ans;
    }
};