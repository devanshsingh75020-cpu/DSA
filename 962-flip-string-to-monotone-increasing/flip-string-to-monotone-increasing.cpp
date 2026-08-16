class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count_of_ones = 0;
        int flips = 0;
        
        for(char &ch : s) {
            if(ch == '1')
                count_of_ones++;
            else {
                flips = min(flips+1, count_of_ones);
            }
        }
        
        return flips;
    }
};