class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> ctos;
        map<string, char> stoc;
        istringstream iss(s);
        string word;
        for(int i = 0; i < pattern.size(); ++i){
            char c = pattern[i];
            iss >> word;
            if(ctos.find(c) == ctos.end()) ctos[c] = word;
            if(stoc.find(word) == stoc.end()) stoc[word] = c;
            if(ctos[c] != word || stoc[word] != c) return 0;
        }
        if(iss >> word) return 0;
        return 1;
    }
};