class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> passengerStatuses;
        for(auto trip : trips){
            passengerStatuses.push_back({trip[1], trip[0]});
            passengerStatuses.push_back({trip[2], -trip[0]});
        }
        sort(passengerStatuses.begin(), passengerStatuses.end());
        int cur = 0;
        for(auto passengerStatus : passengerStatuses){
            cur += passengerStatus.second;
            if(cur > capacity) return 0;
        }
        return 1;
    }
};