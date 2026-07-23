class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int m=hand.size();
        if(m % groupSize!=0)
        {
            return false;
        }
          map<int, int> mp;

        for (int handNumber : hand) {
            mp[handNumber]++;
        }

        while (!mp.empty()) {
            int curr = mp.begin()->first;  // smallest card

            for (int i = 0; i < groupSize; i++) {
                if (mp[curr + i] == 0) {
                    return false;
                }

                mp[curr + i]--;

                if (mp[curr + i] ==0) {
                    mp.erase(curr + i);
                }
            }
        }

        return true;
    }
};