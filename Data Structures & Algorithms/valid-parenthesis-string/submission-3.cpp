class Solution {
    // bool f(int ind, string& s, int open, vector<vector<int>>& dp) {
    //     if(ind == s.size()) return open==0;
    //     if(open > s.size()/2) return false;
    //     if(dp[ind][open] != -1) return dp[ind][open];
    //     if(s[ind] == '(') {
    //         return dp[ind][open] = f(ind+1, s, open+1, dp);
    //     } else if(s[ind] == ')') {
    //         return dp[ind][open] = f(ind+1, s, open-1, dp);
    //     } else {
    //         return dp[ind][open] = f(ind+1, s, open-1, dp) || f(ind+1, s, open+1, dp) || f(ind+1, s, open, dp);
    //     }
    // }
public:
    bool checkValidString(string s) {
        // int n = s.size();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // return f(0, s, 0, dp);
        int leftMin = 0, leftMax = 0;
        for(char c: s) {
            if(c == '(') {
                leftMin++;
                leftMax++;
            } else if ( c == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }
            if(leftMax < 0) return false;
            if(leftMin < 0) leftMin = 0;
        }
        return leftMin == 0;
    }
};
