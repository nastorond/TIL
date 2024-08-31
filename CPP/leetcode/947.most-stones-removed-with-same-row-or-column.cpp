/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution {
public:
    vector<bool> visited;
    int lim;

    void bruteForce(int cur, vector<vector<int>>& stones) { 
        visited[cur] = true;
        for (int i=0; i<lim; i++) {
            if (!visited[i] && (stones[cur][0] == stones[i][0] || stones[cur][1] == stones[i][1])) {
                bruteForce(i, stones);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        if (stones.size() == 1) return 0;
    
        int ret=0;
        lim = stones.size();
        
        visited.resize(lim, false);
        
        for (int i=0; i<lim; i++) {
            if (visited[i]) continue;
            ret++;
            bruteForce(i, stones);
        }

        return lim - ret;
    }
};
// @lc code=end

