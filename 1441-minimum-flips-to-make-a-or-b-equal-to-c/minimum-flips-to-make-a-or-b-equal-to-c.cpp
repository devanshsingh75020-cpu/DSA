class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        int orab = a|b;

        for(int i=0; i<32; i++){
        int bitA = (a & (1<<i))>>i;
        int bitB = (b & (1<<i))>>i;
        int bitC = (c & (1<<i))>>i;
        int x = (orab & (1<<i))>>i;

        if(x != bitC){
            if(bitA == 0 && bitB==0){
               if(bitC==1){
                cnt++;
               }
            }
            else if((bitA == 0 && bitB == 1) || (bitA == 1 && bitB == 0)){
                if(bitC==0){
                    cnt++;
                }
            }
            else if(bitA ==1 && bitB==1){
                if(bitC==0){
                    cnt+=2;
                }
            }
        }
        }
        return  cnt;
    }
};