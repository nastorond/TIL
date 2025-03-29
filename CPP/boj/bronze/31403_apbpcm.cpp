#include <iostream>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    std::string a, b;
    int c;
    cin >> a >> b >> c;

    int iA = std::stoi(a);
    int iB = std::stoi(b);

    std::cout << iA + iB - c << "\n";

    std::cout << std::stoi(a + b) - c << "\n";

    return 0;
}