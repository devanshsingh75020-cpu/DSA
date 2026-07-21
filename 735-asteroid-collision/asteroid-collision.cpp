class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;

        for(int x : asteroids){
            bool destroyed=false;
            if(x>0) {
                destroyed=false;
            }
           while(!st.empty() && st.top() > 0 && x < 0 && st.top() < abs(x)){
                st.pop();
                destroyed=false;
            }

            if(!st.empty() && st.top() > 0 && x < 0){

                if(st.top() == abs(x)){
                    st.pop(); 
                    destroyed=true;
                }
                else{
                    destroyed=true;
                }
            }
            if(!destroyed){
                st.push(x);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};