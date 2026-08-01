class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int swaps = 0;

        unordered_map<int, int> pos;
        for(int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }
        for(int i = 0; i < n; i += 2) {
            int first = row[i];
            int partner = first ^ 1;

            if(row[i + 1] == partner)  continue;

            swaps++;
            int partnerIndex = pos[partner];

            swap(row[i + 1], row[partnerIndex]);

            pos[row[partnerIndex]] = partnerIndex;
            pos[row[i + 1]] = i + 1;
        }
        return swaps;
    }
};