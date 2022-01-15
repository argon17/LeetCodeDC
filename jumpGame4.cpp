

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < n; i++)
            indices[arr[i]].push_back(i);
        vector<bool> visited(n); 
        queue<int> q; 
        q.push(0);
        visited[0] = 1;
        int ans = 0;
        while (q.size()) {
            int sz = q.size();
            while(sz--) {
                int i = q.front(); q.pop();
                if (i == n - 1) return ans;
                vector<int>& todo = indices[arr[i]];
                todo.push_back(i - 1); 
                todo.push_back(i + 1);
                for (int j : todo)
                    if (j >= 0 && j < n && !visited[j]) {
                        q.push(j);
                        visited[j] = 1;
                    }
                todo.clear();
            }
            ++ans;
        }
        return 0;
    }
};
