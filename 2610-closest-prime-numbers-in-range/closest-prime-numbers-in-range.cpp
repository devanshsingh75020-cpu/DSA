class Solution {
public:
    vector<bool> isprime;
    void solve(int n) { // Sieve of Eratosthenes
        isprime.assign(n + 1, true);

        isprime[0] = false;
        isprime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isprime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isprime[j] = false;
                }
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        solve(right);
        vector<int> arr;

        for (int i = left; i <= right; i++) {
            if (isprime[i]) {
                arr.push_back(i);
            }
        }

        int mini = INT_MAX;
        int num1 = -1;
        int num2 = -1;

        for (int i = 0; i + 1 < arr.size(); i++) {
            int diff = arr[i + 1] - arr[i];

            if (diff < mini) {
                mini = diff;
                num1 = arr[i];
                num2 = arr[i + 1];
            }
        }
        return {num1, num2};
    }
};