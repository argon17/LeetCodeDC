class Node{
public:
    bool isEnd;
    Node* next[26];
    Node(){
        for(int i = 0; i < 26; ++i)
            next[i] = NULL;
        isEnd = false;
    }
};
class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char c : word){
            if(!node -> next[c - 'a'])
                node -> next[c-'a'] = new Node();
            node = node -> next[c - 'a'];
        }
        node -> isEnd = true;
    }
    
    bool search(string word) {
        return search(word.c_str(), root);
    }
    
private:
    Node* root = new Node();
    
    bool search(const char* word, Node* node) {
        for(int i = 0; word[i] != '\0' && node; ++i){
            if(word[i] != '.')
                node = node -> next[word[i] - 'a'];
            else{
                Node* temp = node;
                for(int j = 0; j < 26; ++j){
                    node = temp -> next[j];
                    if(search(word + i + 1, node)) return true;
                }
            }
        }
        return node && node -> isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */