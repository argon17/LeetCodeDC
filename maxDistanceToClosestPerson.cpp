class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = -1, cur = 0;
        for(int seat : seats){
            if(seat == 0) ++cur;
            else {
                ans = max(ans, ans == -1 ? cur : (cur + 1) / 2);
                cur = 0;
            }
        }
        return max(ans, cur);
    }
};