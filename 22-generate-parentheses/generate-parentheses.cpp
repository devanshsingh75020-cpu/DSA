class Solution {
public:
    vector<string>ans;
    void solve(string curr, int n, int close, int open){
        if(curr.size() == 2*n){
            if(open == close){
                ans.push_back(curr);
            }
            return;
        }
        if(close <= open){
            solve(curr + ')' , n, close+1, open);
            solve(curr + '(' , n, close, open+1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        solve("",n,0,0);
        return ans;
    }
};