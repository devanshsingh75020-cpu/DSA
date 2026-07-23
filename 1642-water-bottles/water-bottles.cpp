class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full=numBottles;
        int empty=0;
        int drink=0;

        while(full >0){
            drink+=full;
            empty+=full;
            full=empty / numExchange;
            empty=empty % numExchange;
        }
        return drink;
    }
};