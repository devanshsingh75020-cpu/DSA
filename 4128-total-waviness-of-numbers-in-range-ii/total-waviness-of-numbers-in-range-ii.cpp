class Solution {
public:
    string s;
    int n;
    pair<long long, long long>dp[20][20][20][2];

    pair<long long, long long> solve(int curr, int prevprev, int prev, bool islimitedactualno,bool isleadingzero){
        if (curr == n)
            return {1, 0};
        
        if (!islimitedactualno && dp[curr][prevprev + 1][prev + 1][isleadingzero].first != -1)
            return dp[curr][prevprev + 1][prev + 1][isleadingzero];

        long long totalno = 0;
        long long totalwave = 0;

        int limitdigit = islimitedactualno ? s[curr] - '0' : 9;

        for (int digit = 0; digit <= limitdigit; digit++) {

            bool newisleadingzero = isleadingzero && (digit == 0);
            bool newislimitedactualno = 
            
            
            
             islimitedactualno && (digit == limitdigit);

            int newprevprev = prev;
            int newprev = prev;

            int add = 0;

            if (newisleadingzero) {
                newprevprev = -1;
                newprev = -1;
            }
            else if (isleadingzero) {
                newprevprev = -1;
                newprev = digit;
            }
            else {
                if (prevprev != -1) {
                    bool ispeak = (prev > prevprev && prev > digit);
                    bool isvalley = (prev < prevprev && prev < digit);

                    if (ispeak || isvalley)
                        add = 1;
                }

                newprevprev = prev;
                newprev = digit;
            }

            auto [remaintotalno, remaintotalwave] = solve(curr + 1,newprevprev,newprev,newislimitedactualno,
                      newisleadingzero);

            totalno += remaintotalno;
            totalwave += remaintotalwave + 1LL * add * remaintotalno;
        }
        if (!islimitedactualno)
            dp[curr][prevprev + 1][prev + 1][isleadingzero] = {totalno, totalwave};

        return {totalno, totalwave};
    }

    long long func(long long num) {
        //if (num < 0)
            //return 0;

        s = to_string(num);
        n = s.size();

        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                for (int k = 0; k < 20; k++)
                    for (int l = 0; l < 2; l++)
                        dp[i][j][k][l] = {-1, -1};

        return solve(0, -1, -1, true, true).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
};