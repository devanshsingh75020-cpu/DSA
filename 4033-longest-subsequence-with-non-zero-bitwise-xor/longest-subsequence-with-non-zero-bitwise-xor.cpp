class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xorr=0;
        int zeroes=0;

        for(int i=0; i<n; i++){
            xorr=xorr^nums[i];
            if(nums[i]==0){
                zeroes++;
            }
        }
        if(zeroes == n) return 0;
        if(xorr == 0) return n-1;

        return n;
    }
};