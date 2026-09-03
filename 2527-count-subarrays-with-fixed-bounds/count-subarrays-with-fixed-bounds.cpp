class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int maxpos=-1,minpos=-1,CI=-1;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] == maxK){
                maxpos=i;
            }

            if(nums[i] == minK){
                minpos=i;
            }

            if(nums[i]>maxK || nums[i]<minK){
                CI=i;
            }

            ans += max(0, min(maxpos,minpos)-CI);
        }
        return ans;
    }
};