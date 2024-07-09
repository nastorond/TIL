#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    for (int z=0; z<m; z++) {
        int i, j, k;
        vector<int> part_vector;

        cin >> i >> j >> k;

        part_vector.resize(j-i+1);
        copy(arr.begin() + i - 1, arr.begin() + j, part_vector.begin());
        sort(part_vector.begin(), part_vector.end());

        // for(auto it: part_vector) {
        //     cout << it << " ";
        // }

        // cout << "\n";

        cout << part_vector[k-1] << "\n";
    }

    return 0;
}
