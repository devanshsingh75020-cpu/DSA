class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        vector<int>cost(n,0);
        
        for(int i=0; i<n; i++){
            cost[i] = abs(s[i]-t[i]);
        }

        int i=0,j=0,len=0,maxlen=0,currcost=0;

        while(j<n){
            currcost += cost[j];
            while(currcost>maxCost){
                currcost-=cost[i];
                i++;
            }
            len=j-i+1;
            maxlen=max(maxlen,len);
            j++;
        }
        return maxlen;
    }
};