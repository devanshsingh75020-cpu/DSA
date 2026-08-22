class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        for(auto op : operations) {
            int oldValue = op[0];
            int newValue = op[1];

            int idx = mp[oldValue];

            nums[idx] = newValue;

            mp.erase(oldValue);
            mp[newValue] = idx;
        }
        return nums;
    }
};