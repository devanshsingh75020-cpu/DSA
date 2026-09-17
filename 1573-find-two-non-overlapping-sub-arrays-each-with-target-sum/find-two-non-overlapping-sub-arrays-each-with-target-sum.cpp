class Solution {
public:
    
    int minSumOfLengths(vector<int>& arr, int target) {
        int i=0, j=0, n=arr.size(),len=0;
        long long sum=0;
        vector<int>minlen(n,INT_MAX);
        int result=INT_MAX , bestmin=INT_MAX;

        while(j<n){
            sum+=arr[j];

            while(sum>target && i<n){
                sum-=arr[i];
                i++;
            }
            if(sum == target){
                len=j-i+1;
                if(i>0 && minlen[i-1]!=INT_MAX)
                  {
                    result=min(result,len+minlen[i-1]);
                  }
                  bestmin=min(bestmin,len);
            }
            minlen[j]=bestmin;
            j++;
        }
        if(result == INT_MAX)
           return -1;

        return result;
    }
};