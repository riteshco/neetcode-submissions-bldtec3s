class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> lastIndex;
        for(int i=0; i<n; i++) {
            lastIndex[s[i]] = i;
        }
        int last = 0;
        int curr_size = 0;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            curr_size++;
            if(last == i && lastIndex[s[i]] == i) {
                ans.push_back(curr_size);
                curr_size = 0;
                last = i+1;
            } else {
                last = max(last, lastIndex[s[i]]);
            }
        }
        return ans;
    }
};
