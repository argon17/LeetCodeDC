class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        for(int mask = 1; mask <= n; mask <<= 1) n ^= mask;
        return n;
    }
};