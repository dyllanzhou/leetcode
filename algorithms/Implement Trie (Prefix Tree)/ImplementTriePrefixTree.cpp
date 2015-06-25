/*Implement Trie (Prefix Tree)
 Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z. 
*/
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        c = ' ';
        type = 1;
    }
    ~TrieNode(){
        
    }
public:    
    char c;
    int type; //1:node,2:leaf
    map<char,TrieNode*> children; 
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie(){
        clean(root);
        root = NULL;
    }
    
    void clean(TrieNode* root){
        if(!root)return;
        map<char,TrieNode*>::iterator it;
        for(it = root->children.begin();it != root->children.end();it++)
            clean(it->second);
        delete root;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* next = root;
        map<char,TrieNode*>::iterator it;
        for(int i = 0;i < word.size();i++){
            it = next->children.find(word[i]);
            if(it==next->children.end()){
                TrieNode* node = new TrieNode();
                node->c = word[i];
                if((i+1) == word.size()) //last char
                    node->type |= 0x2;
                next->children[word[i]] = node;
                next = node;
            }else
                next = it->second;
        }
        if(next)
            next->type |= 0x2;//mark leaf flag
    }

    // Returns if the word is in the trie.
    bool search(string word) {
         TrieNode* next = root;
         int i;
         map<char,TrieNode*>::iterator it;
         for(i = 0;i < word.size();i++){
             it = next->children.find(word[i]);
             if(it == next->children.end())
                return false;
             next = it->second;
         }
         if(i == word.size() && next->type & 0x2)
            return true;
         return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
         TrieNode* next = root;
         int i;
         map<char,TrieNode*>::iterator it;
         for(i = 0;i < prefix.size();i++){
             it = next->children.find(prefix[i]);
             if(it == next->children.end())
                return false;
             next = it->second;
         }
         if(i == prefix.size())
            return true;
         return false;       
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");