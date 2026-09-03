class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        sort(nums1.begin(), nums1.end());

        // Case 1: all elements are even
        bool allEven = true;

        for(int i = 0; i < n; i++) {
            if(nums1[i] % 2 == 1) {
                allEven = false;
                break;
            }
        }

        if(allEven)
            return true;

        // Prefix array:
        // smalloddpr[i] = is there an odd element
        // from index 0 to i?
        vector<bool> smalloddpr(n, false);

        if(nums1[0] % 2 == 1)
            smalloddpr[0] = true;
        else return false;

        for(int i = 1; i < n; i++) {
            if(nums1[i] % 2 == 1 || smalloddpr[i-1])
                smalloddpr[i] = true;
        }

        // For every even element, there must be
        // an odd element before it
        for(int i = 1; i < n; i++) {

            if(nums1[i] % 2 == 1)
                continue;

            if(smalloddpr[i-1] == false)
                return false;
        }

        return true;
    }
};