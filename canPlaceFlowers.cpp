class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int poss = 0, cur = 0, tot = flowerbed.size();
        int l = 0, r = tot - 1;
        
        while(l < tot && flowerbed[l] == 0) ++l;
        if(l == tot) poss += (tot + 1) / 2;
        else poss += l / 2;
        
        while(r > l && flowerbed[r] == 0) --r;
        poss += (tot - 1 - r) / 2;
        
        while(l <= r){
            if(flowerbed[l++] == 0) ++cur;
            else poss += (cur - 1) / 2, cur = 0;
        }
        return poss >= n;
    }
};

// much simpler

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int poss = 0, cur = 1;
        // for beginning and end zeroes : cur / 2
        // for between zeroes : (cur - 1) / 2
        for(int plot : flowerbed){
            if(plot == 0) ++cur;
            else poss += (cur - 1) / 2, cur = 0;
        }
        if(cur) poss += cur / 2;
        return poss >= n;
    }
};