// 50/50 TC passes but too slow :(
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> store(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        for(int ans = 1; q.size(); ++ans){
            int sz = q.size();
            while(sz--){
                string cur = q.front();
                q.pop();
                if(cur == endWord) return ans;
                store.erase(cur);
                for(int i = 0; i < cur.size(); ++i){
                    char c = cur[i];
                    for(char p = 'a'; p <= 'z'; ++p){
                        cur[i] = p;
                        if(store.find(cur) != store.end())
                            q.push(cur);
                    }
                    cur[i] = c;
                }
            }
        }
        return 0;
    }
};

// Optimized !!
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(begin(wordList), end(wordList), endWord) == end(wordList)) return 0;
        // string : [string]
        map<string, vector<string>> adj;
        for(string word : wordList){
            for(int ind = 0; ind < word.size(); ++ind) {
                string pat = word;
                pat[ind] = '*';
                adj[pat].push_back(word);
            }
        }
        queue<string> q;
        set<string> vis;
        q.push(beginWord);
        vis.insert(beginWord);
        for(int ans = 1; q.size(); ++ans){
            int sz = q.size();
            while(sz--){
                string cur = q.front();
                q.pop();
                if(cur == endWord) return ans;
                for(int ind = 0; ind < cur.size(); ++ind){
                    string pat = cur;
                    pat[ind] = '*';
                    for(string nbr : adj[pat])
                        if(vis.find(nbr) == vis.end()){
                            q.push(nbr);
                            vis.insert(nbr);
                }
            }
        }
        return 0;
    }
};