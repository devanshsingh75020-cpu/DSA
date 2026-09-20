class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;

        arr.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            arr.push_back(max(nums[i], arr[i-1]));
        }

        for(int i = 2; i < n; i++){
            if(arr[i-2] > nums[i]){
                return false;
            }
        }

        return true;
    }
};