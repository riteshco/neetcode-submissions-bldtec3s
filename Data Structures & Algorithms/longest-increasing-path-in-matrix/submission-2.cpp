class Solution {
    int f(int r, int c, vector<vector<int>>& matrix, int parent, vector<vector<int>>& dp) {
        if(r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size() || matrix[r][c] <= parent) return 0;
        if(dp[r][c] != -1) return dp[r][c];

        int ans = 0;
        ans = max(ans, f(r+1, c, matrix, matrix[r][c], dp));
        ans = max(ans, f(r-1, c, matrix, matrix[r][c], dp));
        ans = max(ans, f(r, c+1, matrix, matrix[r][c], dp));
        ans = max(ans, f(r, c-1, matrix, matrix[r][c], dp));
        return dp[r][c] = ans + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans = max(ans, f(i, j, matrix, -1, dp));
            }
        }
        return ans;
    }
};
