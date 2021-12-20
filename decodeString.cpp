class Solution {
public:
	string decodeString(string s) {
		int i = 0;
		return decodeFrom("1[" + s + "]", i);
	}
private:
	// decode k[...]
	string decodeFrom(string s, int &i) {
		string ans;
		int n = s.size();
		int count = 0;
		while (s[i] != '[') (count *= 10) += (s[i++] - '0');
		// "["
		++i;
		while (i < n && s[i] != ']') {
			if (s[i] >= 'a' && s[i] <= 'z') ans += s[i++];
			else ans += decodeFrom(s, i);
		}
		// "]"
		++i;
		string res;
		while (count--) res += ans;
		return res;
	}
};