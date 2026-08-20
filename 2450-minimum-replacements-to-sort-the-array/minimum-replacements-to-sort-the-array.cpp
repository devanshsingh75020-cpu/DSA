class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long op=0;

        for(int i=n-1; i>0; i--){
            if(nums[i] < nums[i-1]){
                int parts=ceil((double)nums[i-1]/nums[i]);
                int mini=nums[i-1]/parts;
                op+=(parts-1);
                nums[i-1]=mini;
            }
        }
        return op;
    }
};