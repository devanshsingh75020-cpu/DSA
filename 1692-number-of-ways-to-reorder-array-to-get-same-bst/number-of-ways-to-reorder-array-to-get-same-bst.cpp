class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while(b>0) {
            if(b % 2 == 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b /= 2;
        }

        return ans;
    }

    long long comb(int n, int r) {
        long long factN = 1;
        long long factR = 1;
        long long factNR = 1;

        for(int i = 1; i <= n; i++) {
            factN = factN * i % MOD;

            if(i == r)
                factR = factN;

            if(i == n-r)
                factNR = factN;
        }

        long long ans = factN;

        ans = ans * power(factR, MOD - 2) % MOD;
        ans = ans * power(factNR, MOD - 2) % MOD;

        return ans;
    }

    long long solve(vector<int> arr) {
        if(arr.size() <= 2)
            return 1;

        vector<int> left, right;

        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] < arr[0])
                left.push_back(arr[i]);
            else
                right.push_back(arr[i]);
        }

        int l = left.size();
        int r = right.size();

        long long ans = comb(l + r, l);

        ans = ans * solve(left) % MOD;
        ans = ans * solve(right) % MOD;

        return ans;
    }

    int numOfWays(vector<int>& nums) {
        return (solve(nums) - 1 + MOD) % MOD;
    }
};