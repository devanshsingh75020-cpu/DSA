class Router {
public:
    deque<vector<int>>q;
    unordered_map<int,deque<int>>mp;
    unordered_set<string> seen;
    int limit;

    Router(int memoryLimit) {
        limit=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
         string key = to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);

         if (seen.count(key))
            return false;

        if(q.size() == limit){
            auto packet=q.front();
            q.pop_front();

            int s = packet[0];
            int d = packet[1];
            int t = packet[2];

            string oldKey = to_string(s) + "#" + to_string(d) + "#" + to_string(t);

            seen.erase(oldKey);
            mp[d].pop_front();
            if (mp[d].empty())
                mp.erase(d);

        }
        q.push_back({source, destination, timestamp});
        seen.insert(key);
        mp[destination].push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty())
            return {};

        auto packet = q.front();
        q.pop_front();

        int s = packet[0];
        int d = packet[1];
        int t = packet[2];

        string key = to_string(s) + "#" + to_string(d) + "#" + to_string(t);

        seen.erase(key);

        mp[d].pop_front();
        if (mp[d].empty())
            mp.erase(d);

        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(!mp.count(destination))
            return 0;

        auto &dq = mp[destination];

        auto l = lower_bound(dq.begin(), dq.end(), startTime);
        auto r = upper_bound(dq.begin(), dq.end(), endTime);

        return r - l;
    }
};