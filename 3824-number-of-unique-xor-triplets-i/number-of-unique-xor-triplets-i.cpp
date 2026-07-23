class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();

        if (n<=2) return n;
        int val=0;
        int i=2;

        while(val <= n){
            val=pow(2,i);
            i++;
        }
        return val;
    }
};