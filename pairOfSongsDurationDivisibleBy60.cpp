class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        vector<int> mod60Count(60);
        for(int t : time){
            ans += mod60Count[(60 - t % 60) % 60];
            mod60Count[t % 60]++;
        }
        return ans;
    }
};