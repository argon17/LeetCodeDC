class Solution {
public:
    int findComplement(int num) {
        int bits = 0, n = num;
        while(n){
            ++bits;
            n >>= 1;
        }
        // xor with 1 complements the bit.
        return num ^ ((1ll << bits) - 1);
    }
};

// approch 2nd
class Solution {
public:
    int findComplement(int num) {
        for(long mask = 1; mask <= num; mask <<= 1) num ^= mask;
        return num;
    }
};