bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ans = 1, last = points[0][1];
        for(auto point : points)
            if(point[0] > last) {
                ++ans;
                last = point[1];
            }
        return ans;
    }
};