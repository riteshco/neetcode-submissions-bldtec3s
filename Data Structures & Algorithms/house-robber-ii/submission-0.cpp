class Solution {
    // int f(int ind, vector<int>& nums, int n, int loot) {
    //     if(ind == n || ind == n+1) return loot;
    //     int take = f(ind+2, nums, n, loot+nums[ind]);
    //     int notTake = f(ind+1, nums, n, loot);
    //     return max(take, notTake);
    // }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        return max(helper(vector<int>(nums.begin() + 1, nums.end())),
                        helper(vector<int>(nums.begin(), nums.end() - 1)));
    }

    int helper(vector<int> nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp.back();
    }
};
