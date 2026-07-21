class Solution {
public:
    const int mod = 1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        vector<int>diffarr(n+1,0);

        for(int i=0; i<requests.size(); i++){
            int start=requests[i][0];
            int end=requests[i][1];

            diffarr[start]+=1;
            diffarr[end+1]-=1;
        }
        for(int i=1; i<n; i++){
            diffarr[i]+=diffarr[i-1];
        }
        sort(diffarr.begin(),diffarr.end(),greater<int>());
        sort(nums.begin(),nums.end(),greater<int>());

        long long ans=0;
        for(int i=0; i<n; i++){
            ans=(ans+(1LL*diffarr[i]*nums[i])%mod)%mod;
        }
        return ans;
    }
};