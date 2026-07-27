class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int> sorted = queries;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> mpp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int j = 0;
        for(int i=0; i<sorted.size(); i++) {
            while(j < intervals.size() && intervals[j][0] <= sorted[i]) {
                minHeap.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
                j++;
            }
            while(!minHeap.empty() && sorted[i] > minHeap.top().second) {
                minHeap.pop();
            }
            int ans = -1;
            if(!minHeap.empty()) {
                ans = minHeap.top().first;
            }
            mpp[sorted[i]] = ans;
        }
        vector<int> ans;
        for(int q: queries) {
            ans.push_back(mpp[q]);
        }
        return ans;
    }
};
