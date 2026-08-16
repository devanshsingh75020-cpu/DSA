class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,ans=INT_MAX;
        long long sum=nums[0];

        while(i<n && j<n){
            if(sum<target){
                j++;
                if(j<n)
                  sum += nums[j];
            }
            else{
                ans=min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
        }
        return ans == INT_MAX? 0 : ans;
    }
};