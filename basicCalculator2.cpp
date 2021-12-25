class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> toAdd;
        char sign = '+';
        int here = 0;
        for(int i = 0; i < n; ++i){
            char c = s[i];
            if(isDigit(c)) {
                (here *= 10) += c - '0';
            }
            if((!isDigit(c) && c != ' ') || i == n - 1){
                if(sign == '+')
                    toAdd.push(here);
                else if(sign == '-')
                    toAdd.push(-here);
                else{
                    if(sign == '*') here *= toAdd.top();
                    else here = toAdd.top()/here;
                    toAdd.pop();
                    toAdd.push(here);
                }
                here = 0;
                sign = c;
            }
        }
        int ans = 0;
        while(toAdd.size()){
            ans += toAdd.top();
            toAdd.pop();
        }
        return ans;
    }
private:
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
};

// Approach 2 using istringstream

class Solution {
public:
    int calculate(string s) {
        stack<int> toAdd;
        int here;
        char sign = '+';
        istringstream iss(s);
        while(iss >> here){
            if(sign == '+') toAdd.push(here);
            else if(sign == '-') toAdd.push(-here);
            else{
                if(sign == '*') here = toAdd.top() * here;
                else here = toAdd.top() / here;
                toAdd.pop();
                toAdd.push(here);
            }
            iss >> sign;
        }
        int ans = 0;
        while(toAdd.size()){
            ans += toAdd.top();
            toAdd.pop();
        }
        return ans;
    }
};