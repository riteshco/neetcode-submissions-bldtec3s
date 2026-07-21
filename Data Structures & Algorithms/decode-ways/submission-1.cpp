class Solution {
    // int f(int ind, string& s) {
    //     if(ind >= s.size()) return 1;
    //     if(s[ind] - '0' == 0) return 0;
    //     int oneDigit = f(ind+1, s);
    //     int twoDigit = 0;
    //     if(ind+1 < s.size() && stoi(string(1, s[ind]) + s[ind+1]) < 27) {
    //         twoDigit = f(ind+2, s);
    //     } 
    //     return oneDigit + twoDigit;
    // }
public:
    int numDecodings(string s) {
        // return f(0, s);

        int n = s.size();
        vector<int> dp(n+2, 0);
        dp[n+1] = 1;
        dp[n] = 1;
        for(int i=n-1; i>=0; i--) {
            if(s[i] - '0' != 0) {
                int oneTake = dp[i+1];
                int twoTake = 0;
                if(i+1 < n && stoi(string(1, s[i]) + s[i+1]) < 27) {
                    twoTake = dp[i+2];
                }
                dp[i] = oneTake + twoTake;
            }
        }

        return dp[0];
    }
};
