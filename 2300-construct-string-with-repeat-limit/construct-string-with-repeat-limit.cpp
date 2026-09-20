class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        vector<int> arr(26, 0);
        string result = "";

        for(int i = 0; i < n; i++){
            arr[s[i] - 'a']++;
        }

        for(int i = 25; i >= 0; i--){
            char ch = i + 'a';

            if(arr[i] == 0) continue;

            int currfreq = arr[i];

            while(currfreq > 0){
                int take = min(currfreq, repeatLimit);

                for(int k = 0; k < take; k++){
                    result += ch;
                    currfreq--;
                }

                if(currfreq == 0)
                    break;

                int j = i - 1;

                while(j >= 0 && arr[j] == 0){
                    j--;
                }

                if(j < 0)
                    break;

                result += char(j + 'a');
                arr[j]--;
            }
        }

        return result;
    }
};