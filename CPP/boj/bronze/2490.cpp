// 윷놀이 b3
#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    for (int i=0; i<3; i++) {
        int cnt = 0;
        for (int j=0; j<4; j++) {
            int tmp;
            cin >> tmp;
            if (tmp) cnt++;
        }
        switch (cnt) {
        case 0:
            cout << 'D' << "\n";
            break;
        case 1:
            cout << 'C' << "\n";
            break;
        case 2:
            cout << 'B' << "\n";
            break;
        case 3:
            cout << 'A' << "\n";
            break;
        case 4:
            cout << 'E' << "\n";
            break;
        }
    }

    return 0;
}