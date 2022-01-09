class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, d = 0;
        vector<vector<int>> dxy = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(char instruction : instructions){
            if(instruction == 'R') (d += 1) %= 4;
            else if(instruction == 'L') (d += 3) %= 4;
            else x += dxy[d][0], y += dxy[d][1];
        }
        return x == 0 && y == 0 || d ;
    }
};