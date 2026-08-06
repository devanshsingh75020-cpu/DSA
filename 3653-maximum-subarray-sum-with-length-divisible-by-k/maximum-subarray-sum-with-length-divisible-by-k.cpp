class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n, 0);
        pre[0] = nums[0];

        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        long long maxsum = LLONG_MIN;

        for(int start = 0; start < k; start++) {
            long long currsum = LLONG_MIN;
            int i = start;

            while(i + k - 1 < n) {
                int j = i + k - 1;
                long long subsum;
                
                if(i > 0)
                    subsum = pre[j] - pre[i - 1];
                else
                    subsum = pre[j];

                if(currsum == LLONG_MIN)  currsum = subsum;
                else  currsum = max(subsum, currsum + subsum);

                maxsum = max(maxsum, currsum);
                i += k;
            }
        }
        return maxsum;
    }
};