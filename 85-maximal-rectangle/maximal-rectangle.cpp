class Solution {
public:
    int largestRectangleArea(vector<int>&heights){
        stack<int>st;
        int n=heights.size();
        int maxArea=0;
        vector<int>nsl(n,-1);
        vector<int>nsr(n,n);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                nsr[i]=st.top();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for(int i=0; i<n;  i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                nsl[i]=st.top();
            }
            st.push(i);
        }

        for(int i=0; i<n; i++){
            maxArea=max(maxArea,heights[i]*(nsr[i]-nsl[i]-1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> heights(cols, 0);

        int ans = 0;
         for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};