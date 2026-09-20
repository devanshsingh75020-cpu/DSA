class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<long long> arr(n, 0);

        if(nums[0] % modulo == k)
            arr[0] = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] % modulo == k)
                arr[i] = arr[i-1] + 1;
            else
                arr[i] = arr[i-1];
        }

        unordered_map<long long, long long> mp;
        long long result = 0;

        mp[0] = 1;

        for(int i = 0; i < n; i++){
            long long curr = arr[i] % modulo;

            long long need = (curr - k + modulo) % modulo;

            if(mp.find(need) != mp.end())
                result += mp[need];

            mp[curr]++;
        }

        return result;
    }
};