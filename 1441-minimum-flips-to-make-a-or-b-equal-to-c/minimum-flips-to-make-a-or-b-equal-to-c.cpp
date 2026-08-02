class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        for(int i=0;i<32;i++){
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        int bitC = (c >> i) & 1;
        if(bitC==1){
            if((bitA |bitB)==1) continue;
            else cnt++;
        }else{
            if((bitA | bitB)==0) continue;
            else{
                if(bitA==1 && bitB==1) cnt=cnt+2;
                else cnt++;
            }
        }
    }
return  cnt;}
};