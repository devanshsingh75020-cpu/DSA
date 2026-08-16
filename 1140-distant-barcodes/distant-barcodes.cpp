class Solution {
public:
    typedef pair<int,int> T;

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<T> pq;
        unordered_map<int,int> mp;

        int n = barcodes.size();

        for(int x : barcodes) {
            mp[x]++;
        }
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }

        vector<int> ans;
        while(!pq.empty()) {

            vector<T> prev;
            for(int k = 0; k < 2 && !pq.empty(); k++) {
                auto [freq, value] = pq.top();
                pq.pop();

                ans.push_back(value);

                freq--;

                if(freq > 0)
                    prev.push_back({freq, value});
            }
            for(auto x : prev) {
                pq.push(x);
            }
        }
        return ans;
    }
};