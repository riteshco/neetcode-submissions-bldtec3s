class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<pair<int,int>> vec_freq;
        for(auto element: freq) {
            vec_freq.push_back({element.second, element.first});
        }
        sort(vec_freq.rbegin(),vec_freq.rend());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec_freq[i].second);
        }
        return ans;
    }
};
