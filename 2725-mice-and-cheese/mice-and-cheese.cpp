class Solution {
public:
    typedef pair<int,int> P;
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<P>pq;

        int n=reward1.size();
        for(int i=0; i<n; i++){
            pq.push({reward1[i]-reward2[i],i});
        }
        unordered_set<int>idx;

        while(!pq.empty() && k>0){
            idx.insert(pq.top().second);
            pq.pop();
            
            k--;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(idx.count(i)){
                ans+=reward1[i];
            }
            else{
                ans+=reward2[i];
            }
        }
        return ans;

    }
};