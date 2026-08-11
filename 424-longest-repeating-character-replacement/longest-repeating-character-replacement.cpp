class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>count(26,0);
        int l=0,r=0,maxlen=0,maxf=0;

        while(r<s.size()){
            count[s[r]-'A']++;
            maxf=max(maxf,count[s[r]-'A']);

            while(r-l+1 -maxf >k){
                count[s[l]-'A']--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};