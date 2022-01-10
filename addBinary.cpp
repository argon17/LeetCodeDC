class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string ans;
        while(i >= 0 || j >= 0 || carry){
            int s = carry;
            if(i >= 0)
                s += a[i--] - '0';
            if(j >= 0)
                s += b[j--] - '0';
            ans += '0' + (s & 1);
            carry = (s > 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};