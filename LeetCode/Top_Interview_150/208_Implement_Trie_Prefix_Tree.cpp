// This implementation is not mine and is only intended for educational purpose
class Trie {
private:
    vector<Trie*> children;
    bool isEndOfWord;

    Trie* searchPrefix(const string &prefix){
        Trie* node = this;
        for(char c : prefix){
            int index = c - 'a';
            if(!node->children[index])
                return nullptr;
            node = node->children[index];
        }
        return node;
    }
public:
    Trie(): children(26, nullptr), isEndOfWord(false) {}
    
    void insert(string word) {
        Trie* node = this;
        for(char c : word){
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new Trie();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        Trie* node = searchPrefix(word);
        return node != nullptr && node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node = searchPrefix(prefix);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
