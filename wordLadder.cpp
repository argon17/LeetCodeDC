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