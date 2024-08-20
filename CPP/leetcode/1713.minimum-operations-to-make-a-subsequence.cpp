/*
 * @lc app=leetcode id=1713 lang=cpp
 *
 * [1713] Minimum Operations to Make a Subsequence
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int lim = target.size(), n=arr.size(), answer=0;
        vector<pair<int, set<int>>> data;
        vector<pair<int, int>> nums;
        
        pair<int, int> tmp;
        for (int i=0; i<arr.size(); i++) {
            tmp.first = arr[i];
            tmp.second = i;
            nums.push_back(tmp);
        }

        sort(nums.begin(), nums.end());

        for (int i=0; i<lim; i++) {
            int idx = lower_bound(nums.begin(), nums.end(), make_pair(target[i], 0)) - nums.begin();

            set<int> tmpSet; 
            tmpSet; // insert basic val

            while (idx < nums.size() && nums[idx].first == target[i]) {
                tmpSet.insert(nums[idx].second);
                idx++;
            }

            data.push_back(make_pair(target[i], tmpSet));
        }

        int idx = 0;
        for (int i=0; i<lim; i++) {
            
            if (data[i].second.empty()) {
                answer++;
            } else {
                auto tmp = data[i].second.begin();
                while (1) {
                    if (idx < *tmp) {
                        idx = *tmp;
                        break;
                    }
                    tmp++;
                    if (tmp == data[i].second.end()) {
                        answer++;
                        break;
                    }
                }
            }
        }
        return answer;
    }
};
// @lc code=end

