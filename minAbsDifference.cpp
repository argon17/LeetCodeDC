class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int minDiff = 1e7;
        for(int i = 1; i < arr.size(); ++i){
            int curDiff = arr[i] - arr[i - 1];
            if(curDiff < minDiff){
                minDiff = curDiff;
                ans.clear();
                ans.push_back({arr[i-1], arr[i]});
            }
            else if(curDiff == minDiff){
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};