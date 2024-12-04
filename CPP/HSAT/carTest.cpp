#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int main(int argc, char** argv)
{
    int n, q, tmpNum;
    vector<int> nums;
    unordered_map<int, int> res;

    cin >> n >> q;

    while (n--) {
        cin >> tmpNum;
        nums.push_back(tmpNum);
    }
    n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i=0; i<n; i++) {
        res[nums[i]] = (n-i-1) * i;
    }
    
    while (q--) {
        cin >> tmpNum;
        if (res.count(tmpNum) > 0) cout << res[tmpNum] << "\n";
        else cout << 0 << "\n";
    }
    
    
    return 0;
}