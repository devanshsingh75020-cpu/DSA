class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;

        for(int i=1; i<n; i++){
            int diff1=abs(points[i][0]-points[i-1][0]);

            int diff2=max(0,abs(points[i][1]-points[i-1][1])-diff1);

            ans+=diff1+diff2;
        }
        return ans;
    }
};