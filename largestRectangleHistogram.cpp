class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rightNSI = nextSmallerIndex(heights);
        reverse(heights.begin(), heights.end());
        vector<int> leftNSI = nextSmallerIndex(heights);
        reverse(leftNSI.begin(), leftNSI.end());
        for(int &i : leftNSI)
            i = n - 1 - i;
        reverse(heights.begin(), heights.end());
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans = max(ans, (rightNSI[i] - leftNSI[i] - 1) * heights[i]);
        return ans;
    }

private:
    vector<int> nextSmallerIndex(vector<int> &a){
        int n = a.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; --i){
            while(st.size() && a[i] <= a[st.top()])
                st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }    
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size(), ans = 0;
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(st.size() && heights[st.top()] >= heights[i]){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }
};