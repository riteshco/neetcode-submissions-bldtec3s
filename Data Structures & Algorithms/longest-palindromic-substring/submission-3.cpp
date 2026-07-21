class Solution {
    string p(string s, int l, int r) {
        if(s[l] != s[r]) return "";
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        if(s.size() <= 1) return s;
        for(int i=0; i<n-1; i++) {
            string s1 = p(s, i, i+1);
            string s2 = p(s, i, i);
            if(s1.size() > s2.size()) {
                if(ans.size() < s1.size()) ans = s1;
            } else {
                if(ans.size() < s2.size()) ans = s2;
            }
        }
        return ans;
    }
};
