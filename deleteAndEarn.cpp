class Solution {
public:
    int deleteAndEarn(vector<int>& arr) {
        int mx = *max_element(arr.begin(), arr.end());
        vector<int> count(mx + 1, 0);
        vector<int> memo(mx + 1, -1);
        for(int x : arr)
            count[x]++;
        return kitnepointshonge(mx, count, memo);
    }
private:
    int kitnepointshonge(int cur, vector<int> &count, vector<int> &memo){
        if(cur == -1 || cur == 0) return 0;
        if(memo[cur] != -1) return memo[cur];
        int ans1, ans2;
        ans1 = cur * count[cur] + kitnepointshonge(cur - 2, count, memo);
        ans2 = kitnepointshonge(cur - 1, count, memo);
        return memo[cur] = max(ans1, ans2);
    }
};