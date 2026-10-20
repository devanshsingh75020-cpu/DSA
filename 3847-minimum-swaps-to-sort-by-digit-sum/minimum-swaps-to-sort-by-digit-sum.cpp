
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> arr;

        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;

            while(num > 0) {
                sum += num % 10;
                num = num / 10;
            }
            arr.push_back({sum, nums[i], i});
        }

        sort(arr.begin(), arr.end());
        vector<int> pos(n);

        for(int i = 0; i < n; i++) {
            pos[arr[i][2]] = i;
        }

        vector<bool> marked(n, 0);
        int ans = n;

        for(int i = 0; i < n; i++) {
            if(marked[i] == 1) continue;

            int clen = 0;
            int j = i;

            while(marked[j] == 0) {
                marked[j] = 1;
                j = pos[j];
            }
            ans--;
        }

        return ans;
    }
};
