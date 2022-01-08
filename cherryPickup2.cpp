class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof dp);
        return cherryPickupHelper(0, 0, m - 1, n, m, grid);
    }

private:
    int dp[70][70][70] = {};
    int cherryPickupHelper(int r, int c1, int c2, int n, int m, vector<vector<int>> &grid){
        if(r == n) return 0;
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int ans = 0;
        for(int i = -1; i <= 1; ++i)
            for(int j = -1; j <= 1; ++j){
                int nc1 = c1 + i, nc2 = c2 + j;
                if(inside(nc1, m, nc2, m))
                    ans = max(ans, cherryPickupHelper(r + 1, nc1, nc2, n, m, grid));
            }
        int cur = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2] = cur + ans;
    }
    
    bool inside(int r, int n, int c, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }
};