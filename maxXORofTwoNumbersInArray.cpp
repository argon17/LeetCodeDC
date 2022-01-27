class TrieNode{
public:
    TrieNode *next[2];
    TrieNode(){
        this->next[0] = NULL;
        this->next[1] = NULL;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for(auto &n : nums) 
            insert(n);
        int ans = 0;
        for(auto n : nums)
            ans = max(ans, maxXOR(n));
        return ans;
    }
    
private:
    TrieNode *root;
    void insert(int x){
        TrieNode *t = root;
        bitset<32> bits(x);
        
        for(int j = 31; j >= 0; j--){
            if(!t -> next[bits[j]]) 
                t -> next[bits[j]] = new TrieNode();
            t = t -> next[bits[j]];
        }    
    }
    
    int maxXOR(int n){
        TrieNode *t = root;
        bitset<32> bits(n);
        int ans = 0; 
        for(int j = 31; j >= 0; j--){
            if(t -> next[!bits[j]]) {
                ans += (1 << j);
                t = t -> next[!bits[j]];
            }
            else 
                t = t -> next[bits[j]];
        }
        return ans;
    }
};