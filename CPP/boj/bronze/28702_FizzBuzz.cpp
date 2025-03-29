#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    std::vector<std::string> numInfos(3);
    int cnt = 0;

    for(int i=0; i<3; i++)
    {
        std::cin >> numInfos[i];
        if (numInfos[i] != "Fizz" && numInfos[i] != "Buzz" && numInfos[i] != "FizzBuzz")
        {
            cnt = i;
        }
    }

    int num = std::stoi(numInfos[cnt]);

    while(cnt < 3)
    {
        num++;
        cnt++;
    }

    const bool isBuzz = static_cast<bool>(num%5 == 0);
    const bool isFizz = static_cast<bool>(num%3 == 0);
    if (isBuzz && isFizz)
    {
        std::cout << "FizzBuzz\n";
    }
    else if (isBuzz)
    {
        std::cout << "Buzz\n";
    }
    else if (isFizz)
    {
        std::cout << "Fizz\n";
    }
    else
    {
        std::cout << num << "\n";
    }

    return 0;
}