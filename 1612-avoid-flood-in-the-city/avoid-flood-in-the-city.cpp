class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int> mp;
        vector<int> zero;
        int n = rains.size();

        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
 
            if(rains[i] > 0) {
                int lake = rains[i];
                if(mp.find(lake) != mp.end()) {
                    int lastday = mp[lake];
                    auto it = upper_bound(zero.begin(),zero.end(),lastday);

                    if(it == zero.end())
                        return {};

                    int dryday = *it;
                    ans[dryday] = lake;
                    zero.erase(it);
                }
                mp[lake] = i;
            }
            else {
                zero.push_back(i);
                ans[i]=1;

            }
        }
        return ans;
    }
};