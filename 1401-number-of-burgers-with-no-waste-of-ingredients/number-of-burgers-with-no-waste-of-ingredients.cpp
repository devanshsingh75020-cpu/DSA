class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int a = tomatoSlices-2*cheeseSlices;

        if(a % 2 == 0 && a>=0){
            int b=a/2;
            if(cheeseSlices-b >=0)
            return {b,cheeseSlices-b};
        }
        return {};
    }
};