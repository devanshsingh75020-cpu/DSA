class Solution {
public:
    int maxDistance(string s, int k) {
        int maxdist=INT_MIN;
        int dist=0;
        int steps=0;
        int e=0,w=0,n=0,so=0;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='N'){
                n++;
            }
            else if(s[i]=='S'){
                so++;
            }
            else if(s[i]=='E'){
                e++;
            }
            else{
                w++;
            }
            dist=abs(e-w)+abs(n-so);
            int extrainc=0;
            int waste=i+1-dist;
            
            if(i!=dist){
                extrainc=min(waste,2*k);
            }

            maxdist=max(maxdist,extrainc+dist);
        }
        return maxdist;
    }
};