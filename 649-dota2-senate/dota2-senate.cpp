class Solution {
public:
    string predictPartyVictory(string senate) {
    
        int r = 0;
        int d = 0;

        for(int i = 0; i < senate.size(); i++) {
            if(senate[i] == 'R') r++;
            else d++;
        }

        int idx = 0;
        while(r > 0 && d > 0) {

            if(senate[idx] == 'R') {
                int i = (idx + 1) % senate.size();
                while(i != idx) {
                    if(senate[i] == 'D') {
                        senate.erase(i, 1);
                        d--;
                        if(i < idx) idx--;
                        break;
                    }
                    i = (i + 1) % senate.size();
                }
            }

            else {
                int i = (idx + 1) % senate.size();
                while(i != idx) {
                    if(senate[i] == 'R') {
                        senate.erase(i, 1);
                        r--;
                        if(i < idx) idx--;
                        break;
                    }
                    i = (i + 1) % senate.size();
                }
            }
            idx = (idx + 1) % senate.size();
        }
        if(r > 0) return "Radiant";
        return "Dire";
    }
};