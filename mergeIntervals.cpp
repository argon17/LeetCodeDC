public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> cur = intervals[0];
        for(vector<int> interval : intervals){
            if(interval[0] > cur[1]){
                ans.push_back(cur);
                cur = interval;
            }
            else{
                cur[1] = max(cur[1], interval[1]);
            }
        }
        ans.push_back(cur);
        return ans;
    }
};