class Solution {
public:
    int myAtoi(string s) {
        int l = 0, r = s.size() - 1;
        while(s[l] == ' ') ++l;
        int sign = 1;
        if(s[l] == '-') sign *= -1, ++l;
        else if(s[l] == '+') ++l;
        while(r >= l && !isDigit(s[r])) --r;
        long ans = 0;
        while(l <= r && isDigit(s[l])) {
            (ans *= 10) +=  s[l++] - '0';
            if(ans * sign <= INT_MIN) return INT_MIN;
            if(ans * sign >= INT_MAX) return INT_MAX;
        }
        return ans * sign;
    }
private:
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
};