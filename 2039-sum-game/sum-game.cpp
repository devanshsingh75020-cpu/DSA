class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int mid = n / 2;

        int leftsum = 0, rightsum = 0;
        int leftcnt = 0, rightcnt = 0;

        for(int i = 0; i < mid; i++){
            if(num[i] == '?'){
                leftcnt++;
            }
            else{
                leftsum += num[i] - '0';
            }
        }

        for(int i = mid; i < n; i++){
            if(num[i] == '?'){
                rightcnt++;
            }
            else{
                rightsum += num[i] - '0';
            }
        }

        if((leftcnt + rightcnt) % 2 != 0)
            return true;

         if(2 * (leftsum - rightsum) == 9 * (rightcnt - leftcnt)){
            return false;
        }

        return true;
    }
};