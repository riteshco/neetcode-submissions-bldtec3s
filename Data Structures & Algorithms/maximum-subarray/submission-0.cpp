class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int maxSum = INT_MIN;
        int currSum = 0;
        while(r < nums.size()) {
            currSum += nums[r];
            maxSum = max(maxSum, currSum);
            if(currSum < 0) {
                currSum = 0;
                r++;
                l = r;
                continue;
            }
            r++;
        }
        return maxSum;
    }
};
