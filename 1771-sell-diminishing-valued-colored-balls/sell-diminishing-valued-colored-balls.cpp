class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const int MOD = 1e9 + 7;

        sort(inventory.begin(), inventory.end(), greater<int>());

        inventory.push_back(0);

        long long ans = 0;
        long long count = 1;

        for(int i = 0; i < inventory.size()-1 && orders > 0; i++) {
            long long curr = inventory[i];
            long long next = inventory[i+1];

            long long levels = curr - next;
            long long balls = levels * count;

            // Sell complete levels
            if(balls <= orders) {

                long long sum = (curr + next + 1) * levels / 2;

                ans = (ans + sum * count) % MOD;

                orders -= balls;
            }

            // Partial level
            else {
                long long full = orders / count;
                long long rem = orders % count;

                // full levels
                long long low = curr - full;

                long long sum = (curr + low + 1) * full / 2;

                ans = (ans + sum * count) % MOD;

                // remaining balls
                ans = (ans + rem * low) % MOD;

                orders = 0;
            }
            count++;
        }
        return ans;
    }
};