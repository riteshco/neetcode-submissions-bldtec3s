class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int mini = INT_MAX;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] <= nums[right]) {
                mini = min(mini, nums[mid]);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return mini;
    }
};
