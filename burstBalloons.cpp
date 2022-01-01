// BruteForce   O(N!)    23/70 TC passed :(
class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n = a.size();
        if(n == 1) return a[0];
        int mx = 0;
        for(int i = 0; i < n; ++i){
            int here = 0;
            if(i == 0) here += a[i] * a[i + 1];
            else if(i == n - 1) here += a[i - 1] * a[i];
            else here += a[i - 1] * a[i] * a[i + 1];
            int val = a[i];
            a.erase(a.begin() + i);
            here += maxCoins(a);
            a.insert(a.begin() + i, val);
            mx = max(mx, here);
        }
        return mx;
    }
};

//  O(N^2) 70/70 test case passed

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n + 1, vector<int>(n + 1, -1));
        nums.insert(begin(nums), 1);
        nums.insert(end(nums), 1);
        return burstRange(nums, 1, n);
    }
private:
    vector<vector<int>> memo;
    int burstRange(vector<int> &a, int l, int r){
        if(r < l) return 0;
        if(memo[l][r] != -1) return memo[l][r];
        int ans = 0;
        // assuming p'th index is the last balloon burst in this range
        for(int p = l; p <= r; ++p){
            int here = a[l - 1] * a[p] * a[r + 1];
            here += burstRange(a, l, p - 1) + burstRange(a, p + 1, r);
            ans = max(ans, here);
        }
        return memo[l][r] = ans;
    }
};