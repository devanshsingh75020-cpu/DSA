class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        int maxlen=n-(numFriends-1);

        char maxi='a';

        for(int i=0; i<n; i++){
            maxi=max(maxi,word[i]);
        }

        string ans="";
        for(int i=0; i<n; i++){
            if(word[i]==maxi){
                string temp = word.substr(i, min(maxlen, n - i));

                if(temp > ans){
                    ans = temp;
                }
            }
        }
        if(numFriends == 1) return word;
        return ans;
    }
};