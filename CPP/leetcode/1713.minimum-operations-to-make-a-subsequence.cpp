/*
 * @lc app=leetcode id=1713 lang=cpp
 *
 * [1713] Minimum Operations to Make a Subsequence
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> hashing;
        vector<int> tmp;
        int lim=target.size();
        
        for (int i=0; i<lim; i++) hashing[target[i]] = i;
        
        for (int i : arr) {
            if (hashing.find(i) == hashing.end()) continue;
            
            auto it = lower_bound(tmp.begin(), tmp.end(), hashing[i]);
            
            if (it == tmp.end()) {
                tmp.push_back(hashing[i]);
            } else {
                *it = hashing[i];
            }
        }
        
        return lim - tmp.size();
    }
};
// @lc code=end

