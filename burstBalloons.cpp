// O(N!) not AC :(
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