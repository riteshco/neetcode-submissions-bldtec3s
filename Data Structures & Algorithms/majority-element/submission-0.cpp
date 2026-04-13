class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int curr_count = 1;
        int max_count = 0;
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                curr_count++;
            } else {
                if(curr_count > max_count){
                    ans = nums[i-1];
                    max_count = curr_count;
                }
                curr_count = 1;
            }
        }
        if(curr_count > max_count) {
            ans = nums[nums.size()-1];
        }
        return ans;
    }
};