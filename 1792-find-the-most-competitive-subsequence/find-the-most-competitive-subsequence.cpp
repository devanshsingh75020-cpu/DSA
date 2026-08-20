class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.top() > nums[i] && st.size() - 1 + (n - i) >= k) {
                st.pop();
            }
            if(st.size() < k)
                st.push(nums[i]);
        }

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};