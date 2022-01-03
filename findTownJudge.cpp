class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // The person with in-degree - out-degree = N - 1 becomes the judge.
        vector<int> outLessIn(n + 1);
        for(auto t : trust){
            outLessIn[t[0]]--;
            outLessIn[t[1]]++;
        }
        for(int x = 1; x <= n; ++x)
            if(outLessIn[x] == n - 1) return x;
        return -1;
    }
};