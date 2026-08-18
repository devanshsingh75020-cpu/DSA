class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        if(sum1 == sum2)
            return 0;

        if(sum1 > sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i1 = 0;
        int j2 = nums2.size() - 1;

        int diff = sum2 - sum1;
        int count = 0;

        while(diff > 0) {

            int change1 = -1;
            int change2 = -1;

            if(i1 < nums1.size())
                change1 = 6 - nums1[i1];

            if(j2 >= 0)
                change2 = nums2[j2] - 1;

            if(change1 >= change2) {
                if(change1 == 0) break;

                diff -= change1;
                i1++;
            }
            else {
                if(change2 == 0) break;

                diff -= change2;
                j2--;
            }

            count++;
        }
        if(diff > 0)
            return -1;

        return count;
    }
};