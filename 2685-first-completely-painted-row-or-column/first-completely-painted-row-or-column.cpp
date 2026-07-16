class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<int>col(n,0);
        vector<int>row(m,0);

        unordered_map<int,pair<int,int>>mp;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int val=mat[i][j];
                mp[val]={i,j};
            }
        }
        for(int i=0; i<arr.size(); i++){
            int num=arr[i];
            int x=mp[num].first;
            int y=mp[num].second;

            col[y]++;
            row[x]++;

            if(col[y] == m) return i;

            if(row[x] == n) return i;
        }   
        return -1;
    }
};