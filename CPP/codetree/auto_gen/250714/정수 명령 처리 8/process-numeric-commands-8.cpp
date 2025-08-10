#include <iostream>
#include <string>
#include <list>

using namespace std;

int N;
string command[10000];
int A[10000];
list<int> li;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push_front" || command[i] == "push_back") {
            cin >> A[i];
        }
    }

    // Please write your code here.
    for (int cmd=0; cmd<N; cmd++)
    {
        if (command[cmd] == "push_front")
        {
            li.push_front(A[cmd]);
        }
        else if (command[cmd] == "push_back")
        {
            li.push_back(A[cmd]);
        }
        else if (command[cmd] == "pop_front" || command[cmd] == "front")
        {
            cout << li.front() << "\n";
            if (command[cmd] == "pop_front") li.pop_front();
        }
        else if (command[cmd] == "pop_back" || command[cmd] == "back")
        {
            cout << li.back() << "\n";
            if (command[cmd] == "pop_back") li.pop_back();
        }
        else if (command[cmd] == "size")
        {
            cout << li.size() << "\n";
        }
        else if (command[cmd] == "empty")
        {
            if (li.empty()) cout << "1\n";
            else cout << "0\n";
        }
    }

    return 0;
}
