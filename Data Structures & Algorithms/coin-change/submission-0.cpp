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
        return f(0, coins, amount, 0, 0)==INT_MAX? -1 : f(0, coins, amount, 0, 0);
    }
};
