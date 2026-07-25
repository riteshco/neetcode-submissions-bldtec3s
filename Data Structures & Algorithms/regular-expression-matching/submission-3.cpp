class Solution {
    bool f(int i, int j, string& s, string& p) {
        if(i<0) {
            while(j > 0 && p[j] == '*') j-=2;
            return j<0;
        }
        if(j<0) return false;
        if(p[j] == '.' || s[i] == p[j]) {
            return f(i-1, j-1, s, p);
        } else if (p[j] == '*') {
            if(f(i, j-2, s, p)) return true;
            if((p[j-1] == s[i] || p[j-1] == '.') && f(i-1, j, s, p)) return true;
            return false;
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        return f(n1-1, n2-1, s, p);
    }
};
