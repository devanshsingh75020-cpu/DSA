class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        long long total = 2LL * n;
        map<int, set<int>> mp;

        for(auto &seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        for(auto &it : mp) {
            int r = it.first;
            set<int> &s = it.second;

            bool left = true;
            bool middle = true;
            bool right = true;

            // 2 3 4 5
            for(int j = 2; j <= 5; j++) {
                if(s.count(j)) {
                    left = false;
                    break;
                }
            }
            // 4 5 6 7
            for(int j = 4; j <= 7; j++) {
                if(s.count(j)) {
                    middle = false;
                    break;
                }
            }
            // 6 7 8 9
            for(int j = 6; j <= 9; j++) {
                if(s.count(j)) {
                    right = false;
                    break;
                }
            }

            if(left && right) {
                // 2 families
                continue;
            }
            else if(left || middle || right) {
                // 1 family
                total--;
            }
            else {
                // 0 families
                total -= 2;
            }
        }
        return total;
    }
};