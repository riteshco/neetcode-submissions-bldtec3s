class Solution {
private:
    int f(int i, int total, vector<int>& nums, int target, vector<vector<int>>& dp, int totalSum) {
        if(i == nums.size()) return total == target;
        if(dp[i][total + totalSum] != INT_MIN) return dp[i][total+totalSum];
        dp[i][total+totalSum] = f(i+1, total-nums[i], nums, target, dp, totalSum) + f(i+1, total+nums[i], nums, target, dp, totalSum);
        return dp[i][total+totalSum];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(2*totalSum+1, INT_MIN));
        return f(0, 0, nums, target, dp, totalSum);
    }
};
