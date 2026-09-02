class Solution {
public:
    int atmostk(vector<int>& nums,int k)
    {
        int l=0, r=0, count=0;
        unordered_map<int,int> mp;
        if(k<0)
        {
            return 0;
        }
        for(r=0;r<nums.size();r++)
        {
            mp[nums[r]]++;
            
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            count += r - l + 1;
        }return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums, k) - atmostk(nums, k-1);
    }
};