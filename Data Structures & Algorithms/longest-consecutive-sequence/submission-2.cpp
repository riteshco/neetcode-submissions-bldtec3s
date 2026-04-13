class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        set<int> a;
        for(int i : nums){
            a.insert(i);
        }
        nums = {};
        for(int i: a) {
            nums.push_back(i);
        }
        int curr = 1;
        int max_count = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] - nums[i-1] == 1){
                curr++;
            } else {
                max_count = max(max_count, curr);
                curr = 1;
            }
        }
        max_count = max(max_count, curr);
        return max_count;
    }
};
