class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        for(string& s : strs) {
            vector<int> count(26, 0);
            for(char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for(int i=1; i<26; i++) {
                key += ',' + to_string(count[i]);
            }
            mpp[key].push_back(s);
        }
        for(auto& p : mpp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
