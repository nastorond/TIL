/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start
class Solution {
public:
    
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int robotDir = 0;
        int x =0, y=0;
        int maxDist=0;

        set<pair<int, int>> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }
        
        for (int num : commands) {
            if (num == -2) {
                robotDir = robotDir == 0 ? 3 : robotDir-1;
                continue;
            }
            if (num == -1) {
                robotDir = robotDir == 3 ? 0 : robotDir+1;
                continue;
            }
            for (int i=0; i<num; i++) {
                int nx = x + dir[robotDir][0];
                int ny = y + dir[robotDir][1];
                
                if (obstacleSet.count({nx, ny})) break;

                x = nx; y = ny;

                maxDist = max(maxDist, x*x + y*y);
            }
            
        }
        
        return maxDist;
    }
};
// @lc code=end

