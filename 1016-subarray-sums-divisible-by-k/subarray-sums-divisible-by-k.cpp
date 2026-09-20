class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int curr = 0;
        int result = 0;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            curr = (curr + nums[i]) % k;

            if(curr < 0)
                curr += k;

            if(mp.find(curr) != mp.end()) {
                result += mp[curr];
            }
            mp[curr]++;
        }
        return result;
    }
};