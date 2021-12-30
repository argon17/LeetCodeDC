class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> already;
        int cur = 0, ans = 0;
        while(1){
            while(cur < k) {
                (cur *= 10) += 1;
                ++ans;
            }
            cur %= k;
            if(cur == 0) return ans;
            if(already.find(cur) != already.end()) return -1;
            already.insert(cur);
        }
        return -1;
    }
};

// O(1) space, O(K) time

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0) return -1;
        // N mod k  = {0, 1, 2, ..., k - 1};
        // with contradiction and pigeonhole principle,
        // all modes must be different in [1, 11, 111, ..., 11..ktimes]
        int mod = 1;
        for(int length = 1; length <= k; ++length){
            if(mod % k == 0) return length;
            mod = (mod * 10 + 1) % k;
        }
        return 0;
    }
};