class Solution {
    // int f(int i, int j, string& t1, string& t2) {
    //     if(i == -1 || j == -1) return 0;
    //     int ans = 0;
    //     if(t1[i] == t2[j]) {
    //         ans = 1 + f(i-1, j-1, t1, t2);
    //     }
    //     ans = max(ans, max(f(i-1, j, t1, t2), f(i, j-1, t1, t2)));
    //     return ans;
    // }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        // return f(n1-1, n2-1, text1, text2);
        
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        for(int i=1; i<=n1; i++) {
            for(int j=1; j<=n2; j++) {
                int take = 0;
                if(text1[i-1] == text2[j-1]) {
                    take = 1 + dp[i-1][j-1];
                }
                dp[i][j] = max(take, max(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[n1][n2];
    }
};
