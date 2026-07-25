class Solution {
public:
    int maxProduct(int n) {
        vector<int>vec;

        while(n>0){
            int num=n%10;
            n=n/10;
            vec.push_back(num);
        }

        sort(vec.begin(),vec.end());
        int sz=vec.size();

        return vec[sz-1]*vec[sz-2];
    }
};