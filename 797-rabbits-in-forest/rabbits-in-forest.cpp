class Solution {
public:
    int numRabbits(vector<int>& answers) {

        unordered_map<int,int> mp;
        for(int i = 0; i < answers.size(); i++) {
            mp[answers[i]]++;
        }
        int res = 0;
        for(auto it : mp) {

            int num = it.first;
            int freq = it.second;

            int groupSize = num + 1;
            int groups = ceil((double)freq / groupSize);
            res += groups * groupSize;
        }

        return res;
    }
};