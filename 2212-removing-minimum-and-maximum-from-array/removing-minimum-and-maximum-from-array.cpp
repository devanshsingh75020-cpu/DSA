class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int sz = nums.size();

        int minidx = 0;
        int maxidx = 0;

        for (int i = 0; i < sz; i++) {
            if (nums[i] < nums[minidx])
                minidx = i;

            if (nums[i] > nums[maxidx])
                maxidx = i;
        }

        int ans = min({
            max(minidx, maxidx) + 1,              // delete from left
            sz - min(minidx, maxidx),             // delete from right
            min(minidx, maxidx) + 1 +
                sz - max(minidx, maxidx)          // both sides
        });

        return ans;
    }
};