class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        queue<pair<int, string>> q;
        q.push({1, beginWord});
        while(!q.empty()) {
            string word = q.front().second;
            int step = q.front().first;
            q.pop();
            if(word == endWord) return step;
            for(int i=0; i<word.size(); i++) {
                for(char c='a'; c <= 'z'; c++) {
                    char tmp = word[i];
                    word[i] = c;
                    if(s.count(word)) {
                        q.push({step+1, word});
                        s.erase(word);
                    }
                    word[i] = tmp;
                }
            }
        }
        return 0;
    }
};
