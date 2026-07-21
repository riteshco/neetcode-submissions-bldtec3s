class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indeg;
        int n = words.size();
        for(auto& word: words) {
            for(char c : word) {
                adj[c] = unordered_set<char>();
                indeg[c] = 0;
            }
        }
        for(int i=0; i<n-1; i++) {
            string w1 = words[i], w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen)) return "";
            for(int j=0; j<minLen; j++) {
                if(w1[j] != w2[j]) {
                    if(!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        indeg[w2[j]]++;
                    }
                    break;
                }
            }
        }
        string output = "";
        queue<char> q;
        for(auto& p: indeg) {
            if(p.second == 0) {
                output += p.first;
                q.push(p.first);
            }
        }
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            for(auto& e : adj[c]) {
                indeg[e]--;
                if(indeg[e] == 0) {
                    output+=e;
                    q.push(e);
                }
            }
        }
        return output.size() == indeg.size() ? output : "";
    }
};
