class Solution {
    // int f(int ind, vector<int>& nums, int n, int loot) {
    //     if(ind == n || ind == n+1) return loot;
    //     int take = f(ind+2, nums, n, loot+nums[ind]);
    //     int notTake = f(ind+1, nums, n, loot);
    //     return max(take, notTake);
    // }
public:
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // return f(0, nums, n, 0);
        
        int n = nums.size();
        vector<int> dp(n+2, 0);
        for(int i=n-1; i>=0; i--) {
            dp[i] = max(dp[i+1], dp[i+2]+nums[i]);
        }
        return dp[0];
    }
};
