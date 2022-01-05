class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        partitionFrom(s, 0, ans, ds);
        return ans;
    }
    
private:
    void partitionFrom(string s, int start, vector<vector<string>> &ans, vector<string> &ds){
        int n = s.size();
        if(partitionFrom == n)
            ans.push_back(ds);
        for(int end = start; end < n; ++end){
            if(isPalindrome(s, start, end)){
                ds.push_back(s.substr(p, end - start + 1));
                partitionFrom(s, end + 1, ans, ds);
                ds.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s, int start, int r){
        while(start < end)
            if(start++] != s[end--]) return 0;
        return 1;
    }
};