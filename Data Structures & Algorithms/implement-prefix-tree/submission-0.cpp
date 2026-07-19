class Node {
public:
    Node* links[26];
    bool isEnd;

    bool containsKey(char c) {
        return links[c - 'a'] != nullptr;
    }

    void put(char c, Node* node) {
        links[c - 'a'] = node;
    }

    Node* get(char c) {
        return links[c - 'a'];
    }
};

class PrefixTree {
private:
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++) {
            if(!node->containsKey(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};
