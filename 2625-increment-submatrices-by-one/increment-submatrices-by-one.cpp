class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>> diffarr(n, vector<int>(n+1,0));

        for(int i = 0; i < queries.size(); i++) {

            int row1 = queries[i][0];
            int col1 = queries[i][1];
            int row2 = queries[i][2];
            int col2 = queries[i][3];

            for(int row = row1; row <= row2; row++) {
                diffarr[row][col1]++;
                if(col2 + 1 < n)
                    diffarr[row][col2+1]--;
            }
        }

        vector<vector<int>> ans(n, vector<int>(n,0));

        for(int i = 0; i < n; i++) {

            int sum = 0;

            for(int j = 0; j < n; j++) {
                sum += diffarr[i][j];
                ans[i][j] = sum;
            }
        }

        return ans;
    }
};