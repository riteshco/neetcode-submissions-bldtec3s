class Solution {
    int f(int i, vector<int>& coins, int amount, int curr, int num) {
        if(i == coins.size()) {
            if(curr == amount) return num;
            return INT_MAX;
        }
        if(curr == amount) return num;
        if(curr > amount) return INT_MAX;

        int take = f(i, coins, amount, curr+coins[i], num+1);
        int notTake = f(i+1, coins, amount, curr, num);

        return min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // return f(0, coins, amount, 0, 0)==INT_MAX? -1 : f(0, coins, amount, 0, 0);

        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, amount+1));
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int i=1; i<=amount; i++) {
            if(i%coins[n-1] == 0) {
                dp[n-1][i] = i/coins[n-1];
            }
        }
        for(int i = n-2; i >= 0; i--) {
            for(int j = 1; j <= amount; j++) {
                int take = INT_MAX;
                if(j - coins[i] >= 0) take = 1 + dp[i][j - coins[i]];
                int notTake = dp[i+1][j];
                dp[i][j] = min(take, notTake);
            }
        }

        return dp[0][amount]==amount+1 ? -1 : dp[0][amount];
    }
};
