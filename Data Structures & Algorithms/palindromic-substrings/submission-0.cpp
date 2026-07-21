class Solution {
    vector<int> manacher(string s) {
        string t = "#";
        for(int i=0; i<s.size(); i++) {
            t += string(1, s[i]) + "#";
        }
        int n = t.size();
        vector<int> p(n, 1);
        int c = 0, r = 0;
        for(int i=0; i<n; i++) {
            if(i < r) {
                p[i] = min(r-i, p[2*c - i]);
            }
            while(i+p[i] < n && i-p[i] >=0 && t[i+p[i]]==t[i-p[i]]){
                p[i]++;
            }
            if(i+p[i] > r) {
                r = i+p[i];
                c = i;
            }
        }
        return p;
    }
public:
    int countSubstrings(string s) {
        vector<int> p = manacher(s);
        int ans = 0;
        for(int i=0; i<p.size(); i++) {
            if(i%2) {
                ans += (p[i]+1) /2;
            } else {
                ans += p[i]/2;
            }
        }
        return ans;
    }
};
