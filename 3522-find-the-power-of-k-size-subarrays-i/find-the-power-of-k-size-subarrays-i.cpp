class Solution {
public:
    int check(vector<int>& nums, int i, int j) {
        for(int k = i; k < j; k++) {
            if(nums[k] + 1 != nums[k + 1]) {
                return -1;
            }
        }
        return nums[j];
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i <= n - k; i++) {
            int j = i + k - 1;
            ans.push_back(check(nums, i, j));
        }
        return ans;
    }
};