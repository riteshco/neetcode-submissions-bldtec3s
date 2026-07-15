class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> counts1(26, 0);
        vector<int> counts2(26, 0);
        for(int i=0; i<s1.size(); i++) {
            counts1[s1[i] - 'a']++;
            counts2[s2[i] - 'a']++;
        }
        int matches = 0;
        for(int i=0; i<26; i++) {
            if(counts1[i] == counts2[i]) matches++;
        }
        int l = 0;
        int r = s1.size();
        while(r < s2.size()) {
            if(matches == 26) return true;

            counts2[s2[r] - 'a']++;
            if(counts1[s2[r]-'a'] == counts2[s2[r]-'a']) matches++;
            else if (counts1[s2[r]-'a'] + 1 == counts2[s2[r]-'a']) matches--;

            counts2[s2[l] - 'a']--;
            if(counts1[s2[l]-'a'] == counts2[s2[l]-'a']) matches++;
            else if (counts1[s2[l]-'a'] - 1 == counts2[s2[l]-'a']) matches--;            

            r++;
            l++;
        }
        return matches == 26;
    }
};
