class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int zero,ones,ans;
        zero = ones = 0;
        ans=n;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == '1') ones++;
            else zero++; 
        }
        if(s=="1") return 0;
        ans=min(ans,zero);
        ans=min(ans,ones);
        if(ones>=1) ans=min(ans,ones-1);
        if(s[0]=='1' && s[n-1]=='1') ans=min(ans,ones-2);
        return ans;
    }
};