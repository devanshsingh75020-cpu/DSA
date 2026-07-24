class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> S(nums.begin(), nums.end());

        unordered_set<int> pairs;
        for (int a : S) {
            for (int b : S) {
                pairs.insert(a ^ b);
            }
        }

        unordered_set<int> triplets;
        for (int p : pairs) {
            for (int c : S) {
                triplets.insert(p ^ c);
            }
        }

        return triplets.size();
    }
};