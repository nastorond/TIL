/*
 * @lc app=leetcode id=2326 lang=cpp
 *
 * [2326] Spiral Matrix IV
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool condition(int x, int y, int n, int m, vector<vector<int>>& arr) {
        return 0 > x || n <= x || 0 > y || m <= y || arr[x][y] != -1;
    }
    
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ret(m, vector<int>(n, -1));
        
        int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir=0, x=0, y=0;
        
        while (head!=nullptr && ret[x][y]==-1) {
            ret[x][y] = head->val;
            if (condition(x+mv[dir][0], y+mv[dir][1], m, n, ret)) {
                dir = dir==3 ? 0 : dir+1;
            }
            x += mv[dir][0]; 
            y += mv[dir][1];
            head = head->next;
        }
        return ret;
    }
};
// @lc code=end

