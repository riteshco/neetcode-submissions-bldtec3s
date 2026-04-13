class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<pair<int,int>> vec_freq;
        for(auto element: freq) {
            vec_freq.push_back(element);
        }
        sort(vec_freq.begin(),vec_freq.end(),[&](pair<int,int> a, pair<int,int> b) {
            return a.second > b.second;
        });
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec_freq[i].first);
        }
        return ans;
    }
};
