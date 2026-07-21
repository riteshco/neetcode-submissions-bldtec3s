class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        int maxLen = 0;
        for(string word : wordDict) {
            maxLen = max(maxLen, (int)word.size());
        }
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1; i<=n; i++) {
            for(int j=i; j > max(0, i-maxLen); j--) {
                if(st.count(s.substr(j-1, i-j+1)) && dp[j-1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
