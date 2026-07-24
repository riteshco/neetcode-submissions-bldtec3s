class Solution {
    int f(int i, int j, string s, string t, vector<vector<int>>& dp) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int sum = 0;
        if(s[i] == t[j]) {
            sum = f(i+1, j+1, s, t, dp);
        }
        sum += f(i+1, j, s, t, dp);
        return dp[i][j] = sum;
    }
public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return f(0, 0, s, t, dp);
    }
};
