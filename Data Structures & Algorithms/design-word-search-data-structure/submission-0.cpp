class TrieNode {
public:
    vector<TrieNode*> links;
    bool word;

    TrieNode() : links(26, nullptr), word(false) {}

    bool containsKey(char c) {
        return links[c - 'a'] != nullptr;
    }

    void put(char c, TrieNode* node) {
        links[c - 'a'] = node;
    }

    TrieNode* get(char c) {
        return links[c - 'a'];
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();    
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c: word) {
            if(!cur->containsKey(c)) cur->put(c, new TrieNode());
            cur = cur->get(c);
        }
        cur->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(string word, int ind, TrieNode* root) {
        TrieNode* cur = root;

        for(int i=ind; i<word.size(); i++) {
            char c = word[i];
            if(c=='.') {
                for(TrieNode* child : cur->links) {
                    if(child!=nullptr && dfs(word, i+1, child)) return true;
                }
                return false;
            } else {
                if(!cur->containsKey(c)) return false;
                cur = cur->get(c);
            }
        }
        return cur->word;
    }
};
