/*
 * @lc app=leetcode id=2022 lang=cpp
 *
 * [2022] Convert 1D Array Into 2D Array
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int cnt=0, cnt2=0;
        vector<vector<int>> ret;
        vector<int> tmp;
        
        if (m*n < original.size() || m*n > original.size()) return {};
        
        for (int num: original) {
            tmp.push_back(num);
            cnt++;
            if (cnt == n) {
                ret.push_back(tmp);
                tmp.clear();
                cnt=0;
                cnt2++;
                if (cnt2 == m) {
                    return ret;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

