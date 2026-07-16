class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);
        rightMax[n-1] = nums[n-1], leftMax[0] = nums[0];
        for(int i=1; i<n; i++) {
            if(i%k==0) leftMax[i] = nums[i];
            else leftMax[i] = max(leftMax[i-1], nums[i]);

            if((n-i-1)%k==0) rightMax[n-i-1] = nums[n-i-1];
            else rightMax[n-i-1] = max(rightMax[n-i], nums[n-i-1]);
        }
        vector<int> ans;
        for(int i=0; i<n-k+1; i++) {
            ans.push_back(max(rightMax[i], leftMax[i+k-1]));
        }
        return ans;
        // priority_queue<pair<int, int>> pq;
        // vector<int> ans;
        // for(int i=0; i<nums.size(); i++) {
        //     pq.push({nums[i], i});
        //     if(i >= k-1) {
        //         while(pq.top().second < i-k+1) pq.pop();
        //         ans.push_back(pq.top().first);
        //     }
        // }
        // return ans;
    }
};
