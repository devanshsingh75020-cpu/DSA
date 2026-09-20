class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int ans=0;

        for(int i=0; i<n; i++){
            int a=s[i]-'a';
            ans += (i+1)*(26-a);
        }
        return ans;
    }
};