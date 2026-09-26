class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;

        for(auto x : knowledge){
            mp[x[0]] = x[1];
        }

        int i=0, n=s.size();
        string ans="", word="";
        bool foundbracket=false;

        while(i<n){
            if(s[i]=='('){
                word="";
                foundbracket=true;
            }
            else if(s[i]==')'){
                if(mp.find(word)!=mp.end())
                    ans += mp[word];
                else
                    ans += "?";

                foundbracket=false;
            }
            else{
                if(foundbracket)
                    word += s[i];
                else
                    ans += s[i];
            }

            i++;
        }

        return ans;
    }
};