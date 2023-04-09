class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        for(int i = 0; i < 26; i++){
            this->children[i] = NULL;
        }
        this->isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        // ch = word[0];
        int x;

        TrieNode* t = root;
        
        for(int i = 0; i < word.size(); i++){
            x = word[i]-'a';
            if(!t->children[x]){
                t->children[x] = new TrieNode();
            }
            t = t->children[x];

        }
        t->isEnd = true;

        // t = root;
        // TrieNode* t1;
        // while(t){
        //     t1 = nullptr;
        //     for(int i = 0; i < 26; i++){
        //         if(t->children[i]){
        //             cout << char('a' + i) << " ";
        //             t1 = t->children[i];
        //         }
        //     }
        //     t = t1;
        // }
    }
    
    bool search(string word) {
        int x;

        TrieNode* t = root;
        
        for(int i = 0; i < word.size(); i++){
            x = word[i]-'a';
            if(!t->children[x]){
                return false;
            }
            t = t->children[x];

        }
        return t->isEnd == true;
    }
    
    bool startsWith(string word) {
        int x;

        TrieNode* t = root;
        
        for(int i = 0; i < word.size(); i++){
            x = word[i]-'a';
            if(!t->children[x]){
                return false;
            }
            t = t->children[x];

        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */