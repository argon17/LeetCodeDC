class Solution {
public:
   int minimumDeviation(vector<int>& nums) {
       int ans = INT_MAX, mn = INT_MAX;
       priority_queue<int> pq;
       for (int n : nums) {
           n = n & 1 ? n * 2 : n;
           pq.push(n);
           mn = min(mn, n); 
       }
       // keep decreasing maximum element if possible
       while(1 ^ pq.top() & 1){
           int cur = pq.top();
           pq.pop();
           pq.push(cur >> 1);
           mn = min(mn, cur >> 1);
           ans = min(ans, pq.top() - mn);
       }       
       return min(ans, pq.top() - mn);
    }
};