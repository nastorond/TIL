#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> res;
	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		res.push_back(a);
	}
	sort(res.begin(), res.end());
	cout << res[1] << "\n";
}