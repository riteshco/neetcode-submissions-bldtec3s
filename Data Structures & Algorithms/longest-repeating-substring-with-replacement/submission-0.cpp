class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        for(char c = 'A'; c <= 'Z'; c++) {
            int count = 0;
            int l = 0;
            int r = 0;
            while(r < s.size()) {
                if(s[r] == c) count++;
                int currLen = r - l + 1;
                if(currLen - count <= k) {
                    maxLen = max(maxLen, currLen);
                    r++;
                } else {
                    if(s[l] == c) count--;
                    l++;
                }
            }
        }
        return maxLen;
    }
};
