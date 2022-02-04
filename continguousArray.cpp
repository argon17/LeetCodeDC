class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> indOfThisDiff;
        indOfThisDiff[0] = -1;
        int ans = 0, cnt1 = 0, cnt0 = 0;
        for(int i=0; i<nums.size(); ++i){
            // this logic is easy peasy
            if(nums[i]) ++cnt1;
            else ++cnt0;
            if(indOfThisDiff.find(cnt1-cnt0)!=indOfThisDiff.end())
            ans = max(ans, i-indOfThisDiff[cnt1-cnt0]);
            else indOfThisDiff[cnt1-cnt0] = i;
        }
        return ans;
    }
};