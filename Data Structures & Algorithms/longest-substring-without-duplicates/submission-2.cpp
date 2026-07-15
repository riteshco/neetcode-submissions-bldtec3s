class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int maxLen = 0;
        int curr_len = 0;
        int l = 0;
        for(int i=0; i<s.size(); i++) {
            if(mpp.find(s[i]) != mpp.end()) {
                while(l < mpp[s[i]] + 1) {
                    mpp.erase(s[l]);
                    l++;
                }
            }
            maxLen = max(maxLen, i - l + 1);
            mpp[s[i]] = i;
        }
        return maxLen;
    }
};
